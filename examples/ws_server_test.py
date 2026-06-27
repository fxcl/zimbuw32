#!/usr/bin/env python3
# Independent WebSocket client for ws_server (Phase 2). Hits the /ws endpoint on
# a server that shares its HTTP port, and validates:
#   1. The Upgrade handshake succeeds (HTTP/1.1 101) and Sec-WebSocket-Accept
#      matches base64(sha1(client_key + GUID)) -- proves the inlined SHA-1 +
#      Base64 in HTTPModule.zu are correct.
#   2. Text frames echo back for short, empty, 2-byte-length (200 B) and 1 KB
#      payloads -- proves the per-connection thread's recv()/send() frame
#      masking/length handling round-trips.
# Usage: ws_server_test.py [port]   (default 8093)
import socket, base64, os, sys, hashlib

host = "127.0.0.1"
port = int(sys.argv[1]) if len(sys.argv) > 1 else 8093
GUID = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"

s = socket.create_connection((host, port), timeout=5)
key = base64.b64encode(os.urandom(16)).decode()
s.sendall((
    "GET /ws HTTP/1.1\r\n"
    "Host: localhost\r\n"
    "Upgrade: websocket\r\n"
    "Connection: Upgrade\r\n"
    "Sec-WebSocket-Key: %s\r\n" % key
    + "Sec-WebSocket-Version: 13\r\n\r\n"
).encode())

resp = b""
while b"\r\n\r\n" not in resp:
    ch = s.recv(4096)
    if not ch:
        print("FAIL: connection closed during handshake"); sys.exit(2)
    resp += ch
print("handshake:", resp.split(b"\r\n")[0].decode().strip())

expect = base64.b64encode(hashlib.sha1((key + GUID).encode()).digest()).decode()
got = None
for line in resp.split(b"\r\n"):
    if line.lower().startswith(b"sec-websocket-accept:"):
        got = line.split(b":", 1)[1].strip().decode()
accept_ok = (got == expect)
print("accept match:", accept_ok)
if not accept_ok:
    print("  expected:", expect, " got:", got)
    s.close(); sys.exit(2)

def send_text(payload):
    h = bytearray([0x81])              # FIN | text
    mask = os.urandom(4)
    n = len(payload)
    if n < 126:
        h.append(0x80 | n)
    elif n < 65536:
        h.append(0x80 | 126); h += n.to_bytes(2, "big")
    else:
        h.append(0x80 | 127); h += n.to_bytes(8, "big")
    h += mask
    h += bytes(b ^ mask[i % 4] for i, b in enumerate(payload))
    s.sendall(h)

def recv_frame():
    h = s.recv(2)
    if len(h) < 2:
        return None
    opcode = h[0] & 0x0F
    plen = h[1] & 0x7F
    if plen == 126:
        plen = int.from_bytes(s.recv(2), "big")
    elif plen == 127:
        plen = int.from_bytes(s.recv(8), "big")
    data = b""
    while len(data) < plen:
        ch = s.recv(plen - len(data))
        if not ch:
            break
        data += ch
    return opcode, data

cases = [
    ("hello", b"hello"),
    ("empty", b""),
    ("125B (1-byte len boundary)", b"a" * 125),
    ("200B (2-byte len path)", b"b" * 200),
    # 1024 B of valid UTF-8 text (printable ASCII).  This is a TEXT-only slice:
    # recv() returns a Zimbu string, which cannot hold embedded NUL bytes, so
    # arbitrary binary payloads (e.g. bytes(range(256))) are out of scope.
    ("1024B (2-byte len, text)", b"The quick brown fox. " * 49),
]
all_ok = accept_ok
for name, payload in cases:
    send_text(payload)
    rec = recv_frame()
    if rec is None:
        print("FAIL [%s]: no reply" % name); all_ok = False; continue
    op, data = rec
    ok = (op == 1 and data == payload)
    print(("OK   [%s] sent %d -> echoed %d (op=%d)"
           if ok else
           "FAIL [%s] sent %d -> echoed %d (op=%d) mismatch")
          % (name, len(payload), len(data), op))
    if not ok:
        all_ok = False

s.close()
print("RESULT:", "ALL PASS" if all_ok else "FAILURES")
sys.exit(0 if all_ok else 3)

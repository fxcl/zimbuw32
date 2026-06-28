/*
 * Zimbu WEBVIEW -- cross-platform file-scope C backend for the OO Window API.
 *
 * Hosts the per-OS implementation of:
 *   void *zimbu_wv_create(url, title, w, h, x, y, style) -> handle (does NOT pump)
 *   void  zimbu_wv_eval(handle, js)            Zimbu -> JS (fire and forget)
 *   char *zimbu_wv_poll(handle)                drain one JS -> Zimbu msg (caller frees; NULL if none)
 *   int   zimbu_wv_isOpen(handle)              1 while the native window is on screen
 *   void  zimbu_wv_close(handle)               order out / destroy; unregister
 *   void  zimbu_wv_run()                       cooperative pump: process pending native
 *                                              events then return (caller loops).
 *
 * WebViewModule.zu's Window class is a thin dispatcher over these. IMPORT.CHEADER
 * pulls this whole file into the generated TU at file scope (standard C has no
 * nested function definitions, and the macOS message-handler class + the Win32
 * WndProc / COM vtables need file-scope statics).
 *
 * JS -> Zimbu bridge design (sidesteps the Zimbu closure gap, todo.txt:415):
 * the gap blocks calling back INTO a Zimbu function. It does NOT block a pure-C
 * handler (ObjC IMP / GObject GCallback / COM vtable) that buffers messages into
 * a per-window C ring drained by zimbu_wv_poll(). JS posts via
 * window.webkit.messageHandlers.zimbu.postMessage(s); Zimbu drains with poll().
 * Precedent in repo: THREADModule passes (GCallback)gtk_main_quit; webview2_win.h
 * builds COM CompletedHandler vtables in pure C.
 *
 * Host status:
 *  - macOS (__APPLE__): AUTHORITATIVE, gated here. Multi-window WKWebView +
 *    runtime-synthesized WKScriptMessageHandler class (objc_allocateClassPair +
 *    class_addMethod) + per-window FIFO ring. Pure C; no .m, no system headers
 *    (AppKit/WebKit headers are ObjC-only; the emitted TU is a .c in C mode).
 *  - Linux (__linux__): webkit2gtk + GTK3. Multi-window; bridge via
 *    WebKitUserContentManager + a pure-C GCallback. Written from docs, NOT built
 *    on this macOS host; PRELIMINARY until the Linux gate (link + run) passes.
 *  - Windows (_WIN32): WebView2 via webview2_win.h (kept intact). create/run/
 *    close/isOpen wrap the existing single-window backend; eval/poll are
 *    PRELIMINARY (need ICoreWebView2 vtable slots beyond Navigate). NOT built
 *    here; PRELIMINARY until the Windows gate passes.
 *
 * Each OS section is self-contained; only the section matching the build host is
 * compiled, so the macOS regression gate is unaffected by Linux/Win bodies.
 */
#ifndef ZIMBU_WEBVIEW_INT_H
#define ZIMBU_WEBVIEW_INT_H

#include <stdlib.h>
#include <string.h>

/* ===========================================================================
 * macOS -- WKWebView, multi-window, runtime-synthesized message handler.
 * ========================================================================= */
#ifdef __APPLE__

typedef void *id;
typedef void *SEL;
typedef signed char BOOL;
typedef unsigned long NSUInteger;
typedef struct { double x, y, width, height; } ZWRect;

#define zwv_nil ((id)0)
#define zwv_YES ((BOOL)1)
#define zwv_NO  ((BOOL)0)

extern id   objc_msgSend(void);                 /* cast per call site (ABI-exact) */
extern id   objc_getClass(const char *);
extern id   objc_allocateClassPair(id superCls, const char *name, long extra);
extern void objc_registerClassPair(id cls);
extern int  class_addMethod(id cls, SEL name, void *imp, const char *types);
extern SEL  sel_registerName(const char *);

/* NSUTF8StringEncoding == 4. NSString from a UTF-8 C string. */
static id zwv_NSSTR(const char *c) {
  id cls = objc_getClass("NSString");
  return ((id (*)(id, SEL, const char *, unsigned long))objc_msgSend)(
      cls, sel_registerName("stringWithCString:encoding:"), c, 4UL);
}

typedef struct {
  id win;
  id webView;
  id userCC;       /* retained WKUserContentController (keeps the handler alive) */
  id handler;      /* retained synthesized message-handler instance */
  char **msgs;     /* FIFO ring of UTF-8 strings (each malloc'd; caller frees) */
  int   msgCap;
  int   msgHead;
  int   msgTail;
  int   msgCount;
} ZWWindow;

#define ZWV_MAX_WIN 64
static ZWWindow *zwv_registry[ZWV_MAX_WIN];
static int       zwv_registryCount = 0;
static int       zwv_appInited = 0;
static id        zwv_handlerClass = zwv_nil;

static void zwv_ringInit(ZWWindow *zw) {
  zw->msgs = (char **)malloc(sizeof(char *) * 16);
  zw->msgCap = 16;
  zw->msgHead = zw->msgTail = zw->msgCount = 0;
}
static void zwv_ringPush(ZWWindow *zw, const char *utf8) {
  if (!zw->msgs) zwv_ringInit(zw);
  if (zw->msgCount == zw->msgCap) {            /* overflow: drop the oldest */
    free(zw->msgs[zw->msgHead]);
    zw->msgs[zw->msgHead] = NULL;
    zw->msgHead = (zw->msgHead + 1) % zw->msgCap;
    zw->msgCount--;
  }
  zw->msgs[zw->msgTail] = strdup(utf8 ? utf8 : "");
  zw->msgTail = (zw->msgTail + 1) % zw->msgCap;
  zw->msgCount++;
}
static char *zwv_ringPop(ZWWindow *zw) {
  char *m = NULL;
  if (zw->msgCount > 0) {
    m = zw->msgs[zw->msgHead];
    zw->msgs[zw->msgHead] = NULL;
    zw->msgHead = (zw->msgHead + 1) % zw->msgCap;
    zw->msgCount--;
  }
  return m;                                     /* caller frees */
}

/* IMP for userContentController:didReceiveScriptMessage: . Pure C; enqueues the
 * posted string into the ring of the webView that sent it. "v@:@@" = void return,
 * self, _cmd, two object args. */
static void zwv_msgHandler_IMP(id self, SEL cmd, id cc, id msg) {
  (void)self; (void)cmd; (void)cc;
  if (!msg) return;
  id body = ((id (*)(id, SEL))objc_msgSend)(msg, sel_registerName("body"));
  if (!body) return;
  /* description returns self for NSString, a readable form for any NSObject. */
  id desc = ((id (*)(id, SEL))objc_msgSend)(body, sel_registerName("description"));
  if (!desc) return;
  const char *utf8 =
      ((const char *(*)(id, SEL))objc_msgSend)(desc, sel_registerName("UTF8String"));
  if (!utf8) return;
  id wv = ((id (*)(id, SEL))objc_msgSend)(msg, sel_registerName("webView"));
  int i;
  for (i = 0; i < zwv_registryCount; ++i) {
    if (zwv_registry[i] && zwv_registry[i]->webView == wv) {
      zwv_ringPush(zwv_registry[i], utf8);
      break;
    }
  }
}

/* Build (once) an NSObject subclass implementing WKScriptMessageHandler. */
static id zwv_getHandlerClass(void) {
  if (zwv_handlerClass) return zwv_handlerClass;
  id nsObj = objc_getClass("NSObject");
  zwv_handlerClass = objc_allocateClassPair(nsObj, "ZimbuWVMsgHandler", 0);
  if (!zwv_handlerClass) return zwv_nil;
  class_addMethod(zwv_handlerClass,
      sel_registerName("userContentController:didReceiveScriptMessage:"),
      (void *)zwv_msgHandler_IMP, "v@:@@");
  objc_registerClassPair(zwv_handlerClass);
  return zwv_handlerClass;
}

static void zwv_appInit(void) {
  if (zwv_appInited) return;
  id app = ((id (*)(id, SEL))objc_msgSend)(objc_getClass("NSApplication"),
                                           sel_registerName("sharedApplication"));
  ((void (*)(id, SEL, long))objc_msgSend)(app, sel_registerName("setActivationPolicy:"), 0L);
  ((void (*)(id, SEL))objc_msgSend)(app, sel_registerName("finishLaunching"));
  ((void (*)(id, SEL, BOOL))objc_msgSend)(app, sel_registerName("activateIgnoringOtherApps:"),
                                          zwv_YES);
  zwv_appInited = 1;
}

static void *zimbu_wv_create(const char *url, const char *title,
                      double w, double h, double x, double y,
                      unsigned long style) {
  zwv_appInit();

  ZWWindow *zw = (ZWWindow *)calloc(1, sizeof(ZWWindow));
  zwv_ringInit(zw);

  /* WKWebViewConfiguration + WKUserContentController + the message handler. The
   * handler must be registered before the page loads so window.webkit.message
   * Handlers.zimbu is present from the first script. */
  id userCC = ((id (*)(id, SEL))objc_msgSend)(objc_getClass("WKUserContentController"),
                                              sel_registerName("alloc"));
  userCC = ((id (*)(id, SEL))objc_msgSend)(userCC, sel_registerName("init"));
  id handlerCls = zwv_getHandlerClass();
  id handler = ((id (*)(id, SEL))objc_msgSend)(handlerCls, sel_registerName("alloc"));
  handler = ((id (*)(id, SEL))objc_msgSend)(handler, sel_registerName("init"));
  ((void (*)(id, SEL, id, id))objc_msgSend)(userCC,
      sel_registerName("addScriptMessageHandler:name:"), handler, zwv_NSSTR("zimbu"));

  id config = ((id (*)(id, SEL))objc_msgSend)(objc_getClass("WKWebViewConfiguration"),
                                              sel_registerName("alloc"));
  config = ((id (*)(id, SEL))objc_msgSend)(config, sel_registerName("init"));
  ((void (*)(id, SEL, id))objc_msgSend)(config, sel_registerName("setUserContentController:"),
                                        userCC);

  ZWRect webFrame = { 0.0, 0.0, w, h };
  id webView = ((id (*)(id, SEL))objc_msgSend)(objc_getClass("WKWebView"),
                                               sel_registerName("alloc"));
  webView = ((id (*)(id, SEL, ZWRect, id))objc_msgSend)(webView,
      sel_registerName("initWithFrame:configuration:"), webFrame, config);
  /* Resize with the window: NSViewWidthSizable(2) | NSViewHeightSizable(16) = 18. */
  ((void (*)(id, SEL, NSUInteger))objc_msgSend)(webView, sel_registerName("setAutoresizingMask:"),
                                                (NSUInteger)18);

  id urlStr = zwv_NSSTR(url);
  id nsurl = ((id (*)(id, SEL, id))objc_msgSend)(objc_getClass("NSURL"),
      sel_registerName("URLWithString:"), urlStr);
  id req = ((id (*)(id, SEL, id))objc_msgSend)(objc_getClass("NSURLRequest"),
      sel_registerName("requestWithURL:"), nsurl);
  ((void (*)(id, SEL, id))objc_msgSend)(webView, sel_registerName("loadRequest:"), req);

  ZWRect frame = { x, y, w, h };
  id win = ((id (*)(id, SEL))objc_msgSend)(objc_getClass("NSWindow"), sel_registerName("alloc"));
  win = ((id (*)(id, SEL, ZWRect, unsigned long, unsigned long, BOOL))objc_msgSend)(win,
      sel_registerName("initWithContentRect:styleMask:backing:defer:"),
      frame, style, 2UL /* NSBackingStoreBuffered */, zwv_NO);
  ((void (*)(id, SEL, id))objc_msgSend)(win, sel_registerName("setTitle:"), zwv_NSSTR(title));
  ((void (*)(id, SEL, id))objc_msgSend)(win, sel_registerName("setContentView:"), webView);
  ((void (*)(id, SEL, id))objc_msgSend)(win, sel_registerName("makeKeyAndOrderFront:"),
                                        zwv_nil);

  zw->win = win;
  zw->webView = webView;
  zw->userCC = userCC;
  zw->handler = handler;
  if (zwv_registryCount < ZWV_MAX_WIN) zwv_registry[zwv_registryCount++] = zw;
  return zw;
}

static void zimbu_wv_eval(void *handle, const char *js) {
  ZWWindow *zw = (ZWWindow *)handle;
  if (!zw || !zw->webView) return;
  /* nil completion handler = fire and forget (documented). */
  ((void (*)(id, SEL, id, id))objc_msgSend)(zw->webView,
      sel_registerName("evaluateJavaScript:completionHandler:"), zwv_NSSTR(js), zwv_nil);
}

static char *zimbu_wv_poll(void *handle) {
  ZWWindow *zw = (ZWWindow *)handle;
  if (!zw) return NULL;
  return zwv_ringPop(zw);
}

static int zimbu_wv_isOpen(void *handle) {
  ZWWindow *zw = (ZWWindow *)handle;
  if (!zw || !zw->win) return 0;
  return ((BOOL (*)(id, SEL))objc_msgSend)(zw->win, sel_registerName("isVisible")) ? 1 : 0;
}

static void zimbu_wv_close(void *handle) {
  ZWWindow *zw = (ZWWindow *)handle;
  if (!zw) return;
  if (zw->win) ((void (*)(id, SEL))objc_msgSend)(zw->win, sel_registerName("close"));
  int i;
  for (i = 0; i < zwv_registryCount; ++i) {
    if (zwv_registry[i] == zw) {
      zwv_registry[i] = zwv_registry[--zwv_registryCount];
      break;
    }
  }
  if (zw->msgs) {
    while (zw->msgCount-- > 0) {
      free(zw->msgs[zw->msgHead]);
      zw->msgHead = (zw->msgHead + 1) % zw->msgCap;
    }
    free(zw->msgs);
  }
  free(zw);
}

/* Cooperative pump: drain all immediately-pending events, then block briefly
 * (~20ms) for the next. Returns so the caller can interleave poll(). The caller
 * loops while any window it cares about is open. */
static void zimbu_wv_run(void) {
  id app = ((id (*)(id, SEL))objc_msgSend)(objc_getClass("NSApplication"),
                                           sel_registerName("sharedApplication"));
  id mode = zwv_NSSTR("kCFRunLoopDefaultMode");
  SEL nextEv = sel_registerName("nextEventMatchingMask:untilDate:inMode:dequeue:");
  SEL sendEv = sel_registerName("sendEvent:");
  id distantPast = ((id (*)(id, SEL))objc_msgSend)(objc_getClass("NSDate"),
                                                   sel_registerName("distantPast"));
  id deadline = ((id (*)(id, SEL, double))objc_msgSend)(objc_getClass("NSDate"),
      sel_registerName("dateWithTimeIntervalSinceNow:"), 0.02);

  /* Phase 1: drain whatever is already queued (non-blocking). */
  for (;;) {
    if (zwv_registryCount == 0) return;
    id ev = ((id (*)(id, SEL, unsigned long, id, id, BOOL))objc_msgSend)(app, nextEv,
        (unsigned long)~0UL, distantPast, mode, zwv_YES);
    if (!ev) break;
    ((void (*)(id, SEL, id))objc_msgSend)(app, sendEv, ev);
  }
  /* Phase 2: wait briefly for one more event (keeps the loop off the CPU). */
  if (zwv_registryCount == 0) return;
  id ev = ((id (*)(id, SEL, unsigned long, id, id, BOOL))objc_msgSend)(app, nextEv,
      (unsigned long)~0UL, deadline, mode, zwv_YES);
  if (ev) ((void (*)(id, SEL, id))objc_msgSend)(app, sendEv, ev);

  /* Phase 3: drop windows closed via the OS close button (now invisible). */
  int i = 0;
  while (i < zwv_registryCount) {
    BOOL vis = ((BOOL (*)(id, SEL))objc_msgSend)(zwv_registry[i]->win, sel_registerName("isVisible"));
    if (vis) ++i;
    else     zwv_registry[i] = zwv_registry[--zwv_registryCount];
  }
}

/* ===========================================================================
 * Linux -- webkit2gtk + GTK3, multi-window, GCallback bridge. PRELIMINARY.
 * ========================================================================= */
#elif defined(__linux__)

typedef struct _GtkWidget GtkWidget;
typedef struct _GtkWindow GtkWindow;
typedef struct _GtkContainer GtkContainer;
typedef struct _WebKitUserContentManager WebKitUserContentManager;
typedef void (*GCallback)(void);

extern GtkWidget *gtk_window_new(int);
extern void gtk_window_set_title(GtkWindow *, const char *);
extern void gtk_window_set_default_size(GtkWindow *, int, int);
extern void gtk_window_move(GtkWindow *, int, int);
extern void gtk_container_add(GtkContainer *, GtkWidget *);
extern GtkWidget *webkit_web_view_new(void);
extern void webkit_web_view_load_uri(GtkWidget *, const char *);
extern void webkit_web_view_run_javascript(GtkWidget *, const char *, void *, void *, void *);
extern WebKitUserContentManager *webkit_web_view_get_user_content_manager(GtkWidget *);
extern int webkit_user_content_manager_register_script_message_handler(
    WebKitUserContentManager *, const char *);
extern unsigned long g_signal_connect_data(void *, const char *, GCallback, void *, void *,
                                           unsigned int);
extern const char *jsc_value_to_string(void *);          /* JSCValue* -> gchar* */
extern void *webkit_javascript_result_get_js_value(void *); /* WebKitJavascriptResult* */
extern void gtk_widget_show_all(GtkWidget *);
extern int gtk_widget_is_visible(GtkWidget *);
extern void gtk_widget_destroy(GtkWidget *);
extern int g_main_context_iteration(void *, int);        /* (NULL, mayBlock) */
extern void g_usleep(unsigned long);

typedef struct {
  GtkWidget *win;
  GtkWidget *wv;
  char **msgs;
  int   msgCap, msgHead, msgTail, msgCount;
} ZWWindow;

static void zwv_ringInit(ZWWindow *zw) {
  zw->msgs = (char **)malloc(sizeof(char *) * 16);
  zw->msgCap = 16;
  zw->msgHead = zw->msgTail = zw->msgCount = 0;
}
static void zwv_ringPush(ZWWindow *zw, const char *utf8) {
  if (!zw->msgs) zwv_ringInit(zw);
  if (zw->msgCount == zw->msgCap) {
    free(zw->msgs[zw->msgHead]);
    zw->msgs[zw->msgHead] = NULL;
    zw->msgHead = (zw->msgHead + 1) % zw->msgCap;
    zw->msgCount--;
  }
  zw->msgs[zw->msgTail] = strdup(utf8 ? utf8 : "");
  zw->msgTail = (zw->msgTail + 1) % zw->msgCap;
  zw->msgCount++;
}
static char *zwv_ringPop(ZWWindow *zw) {
  char *m = NULL;
  if (zw->msgCount > 0) {
    m = zw->msgs[zw->msgHead];
    zw->msgs[zw->msgHead] = NULL;
    zw->msgHead = (zw->msgHead + 1) % zw->msgCap;
    zw->msgCount--;
  }
  return m;
}

/* Pure-C GObject signal callback (a C function pointer, NOT a closure): the
 * "script-message-received::zimbu" emission on the user content manager. */
static void zwv_g_msg(void *self, void *result, void *user_data) {
  (void)self;
  ZWWindow *zw = (ZWWindow *)user_data;
  if (!zw || !result) return;
  void *val = webkit_javascript_result_get_js_value(result);
  if (!val) return;
  const char *s = jsc_value_to_string(val);
  if (s) zwv_ringPush(zw, s);
}

static int zwv_gtkInited = 0;
static void zwv_gtkInit(void) {
  if (zwv_gtkInited) return;
  extern void gtk_init(int *, char ***);
  gtk_init((int *)0, (char ***)0);
  zwv_gtkInited = 1;
}

static void *zimbu_wv_create(const char *url, const char *title,
                      double w, double h, double x, double y,
                      unsigned long style) {
  (void)style;
  zwv_gtkInit();
  ZWWindow *zw = (ZWWindow *)calloc(1, sizeof(ZWWindow));
  zwv_ringInit(zw);
  GtkWidget *win = gtk_window_new(0 /* GTK_WINDOW_TOPLEVEL */);
  gtk_window_set_title((GtkWindow *)win, title);
  gtk_window_set_default_size((GtkWindow *)win, (int)w, (int)h);
  gtk_window_move((GtkWindow *)win, (int)x, (int)y);
  GtkWidget *wv = webkit_web_view_new();
  /* Bridge: register the "zimbu" handler and connect its received signal. */
  WebKitUserContentManager *ucm = webkit_web_view_get_user_content_manager(wv);
  if (ucm) {
    webkit_user_content_manager_register_script_message_handler(ucm, "zimbu");
    g_signal_connect_data((void *)ucm, "script-message-received::zimbu",
                          (GCallback)zwv_g_msg, (void *)zw, (void *)0, 0);
  }
  webkit_web_view_load_uri(wv, url);
  gtk_container_add((GtkContainer *)win, wv);
  gtk_widget_show_all(win);
  zw->win = win;
  zw->wv = wv;
  return zw;
}

static void zimbu_wv_eval(void *handle, const char *js) {
  ZWWindow *zw = (ZWWindow *)handle;
  if (!zw || !zw->wv) return;
  webkit_web_view_run_javascript(zw->wv, js, (void *)0, (void *)0, (void *)0);
}

static char *zimbu_wv_poll(void *handle) {
  ZWWindow *zw = (ZWWindow *)handle;
  if (!zw) return NULL;
  return zwv_ringPop(zw);
}

static int zimbu_wv_isOpen(void *handle) {
  ZWWindow *zw = (ZWWindow *)handle;
  if (!zw || !zw->win) return 0;
  return gtk_widget_is_visible(zw->win) ? 1 : 0;
}

static void zimbu_wv_close(void *handle) {
  ZWWindow *zw = (ZWWindow *)handle;
  if (!zw) return;
  if (zw->win) gtk_widget_destroy(zw->win);
  if (zw->msgs) {
    while (zw->msgCount-- > 0) {
      free(zw->msgs[zw->msgHead]);
      zw->msgHead = (zw->msgHead + 1) % zw->msgCap;
    }
    free(zw->msgs);
  }
  free(zw);
}

static void zimbu_wv_run(void) {
  /* Pump the default main context once (may-block: sleeps until an event or a
   * short internal timeout). The caller loops, interleaving poll(). */
  g_main_context_iteration((void *)0, 1);
}

/* ===========================================================================
 * Windows -- WebView2 via webview2_win.h (kept intact). PRELIMINARY: the OO
 * interface wraps the existing single-window backend; eval/poll need
 * ICoreWebView2 vtable slots beyond Navigate and are stubbed for now.
 * ========================================================================= */
#elif defined(_WIN32)

#include "webview2_win.h"

/* webview2_win.h exposes (after the split below):
 *   zimbu_webview2_create(url, title) -> hwnd handle (non-blocking setup)
 *   zimbu_webview2_pump()              cooperative PeekMessage round (returns 0 on WM_QUIT)
 *   zimbu_webview2_is_open()           IsWindow(zwv_hwnd)
 *   zimbu_webview2_close()             PostMessage WM_CLOSE + PostQuitMessage
 *   zimbu_webview2_open(url, title)    legacy blocking entry (create + pump loop) */

static void *zimbu_wv_create(const char *url, const char *title,
                      double w, double h, double x, double y,
                      unsigned long style) {
  (void)w; (void)h; (void)x; (void)y; (void)style;  /* TODO: CreateWindowExW pos/size */
  return zimbu_webview2_create(url, title);
}

static void zimbu_wv_eval(void *handle, const char *js) {
  (void)handle; (void)js;
  /* PRELIMINARY: needs ICoreWebView2::ExecuteScript (vtable slot beyond the
   * Navigate slot currently transcribed in webview2_win.h). */
}

static char *zimbu_wv_poll(void *handle) {
  (void)handle;
  /* PRELIMINARY: needs add_WebMessageReceived + a COM handler vtable -> ring. */
  return NULL;
}

static int zimbu_wv_isOpen(void *handle) {
  (void)handle;
  return zimbu_webview2_is_open();
}

static void zimbu_wv_close(void *handle) {
  (void)handle;
  zimbu_webview2_close();
}

static void zimbu_wv_run(void) {
  zimbu_webview2_pump();
}

#else
# error "WEBVIEW: unsupported host (need __APPLE__, __linux__, or _WIN32)."
#endif

#endif /* ZIMBU_WEBVIEW_INT_H */

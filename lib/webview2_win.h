/*
 * Zimbu WEBVIEW -- Windows (MinGW) WebView2 backend.
 *
 * Real WebView2 embedding via the Microsoft Edge runtime, loaded dynamically
 * from WebView2Loader.dll (no import lib, no #include <WebView2.h>). Every
 * Win32 and COM symbol is forward-declared here; the COM vtable slot orders
 * are transcribed from the canonical Microsoft WebView2.h (ABI-stable since
 * 1.0). Slots are 0-indexed including the IUnknown trio (QI=0, AddRef=1,
 * Release=2):
 *
 *   ICoreWebView2Environment:  slot 3 = CreateCoreWebView2Controller
 *   ICoreWebView2Controller:   slot 4 = put_IsVisible, 6 = put_Bounds,
 *                              25 = get_CoreWebView2
 *   ICoreWebView2:             slot 5 = Navigate
 *   *CompletedHandler:         slot 3 = Invoke
 *
 * Why a CHEADER (file-scope) rather than a function-body >>> block in
 * WebViewModule.zu: Win32 needs a file-scope WndProc callback + static COM
 * handler vtables, and standard C has no nested function definitions. Zimbu's
 * IMPORT.CHEADER pulls this file into the generated TU at file scope, giving
 * those statics a legal home. The whole body is guarded so non-Windows hosts
 * compile it to nothing (macOS/Linux regression gate stays clean).
 *
 * Provisioning: ship WebView2Loader.dll (x64) next to the exe, from the NuGet
 * package Microsoft.Web.WebView2 (build/native/x64/WebView2Loader.dll). The
 * Edge runtime itself is resolved by the loader (Evergreen). Bitness must
 * match the process.
 */
#ifndef ZIMBU_WEBVIEW2_WIN_H
#define ZIMBU_WEBVIEW2_WIN_H

#ifdef _WIN32

/* ---- Calling conventions: MS x64 ABI collapses these to the default; __stdcall
 *      on 32-bit Windows. Defined so the same source compiles under MinGW and
 *      MSVC, x86 and x64. ----------------------------------------------- */
#if defined(_M_X64) || defined(__x86_64__) || defined(_WIN64) || defined(__amd64__)
#  define ZW_STDCALL
#else
#  define ZW_STDCALL __stdcall
#endif

/* ---- Minimal Win32 + COM forward declarations (no system headers) --------
 * Types are suffixed with _ to avoid any collision should a future Zimbu
 * runtime transitively include <windows.h>. Function names are the real
 * extern symbols (resolved by the linker against the system DLLs via the
 * -luser32/-lole32/-lkernel32 that Config.addWebViewLib() appends on Windows).
 * WPARAM_/LPARAM_/LRESULT_ are pointer-sized: Windows is LLP64 (long=32), so
 * long long is used for the 64-bit register-passed slot values. ----------- */
typedef long              ZWHRESULT;
typedef unsigned long     ZWULONG;
typedef int               ZWBOOL;
typedef unsigned int      ZWUINT;
typedef long              ZWLONG;
typedef unsigned long     ZWDWORD;
typedef long long         ZWLPARAM_;
typedef long long         ZWLRESULT_;
typedef unsigned long long ZWWPARAM_;

typedef void     *ZWHWND_;
typedef void     *ZWHMODULE_;
typedef void     *ZWHINSTANCE_;
typedef void     *ZWHMENU_;
typedef const char    *ZWLPCSTR_;
typedef const wchar_t *ZWLPCWSTR_;
typedef wchar_t       *ZWLPWSTR_;

typedef struct { ZWLONG left, top, right, bottom; } ZWRECT_;
typedef struct {
  ZWHWND_   hwnd;
  ZWUINT    message;
  ZWWPARAM_ wParam;
  ZWLPARAM_ lParam;
  ZWDWORD   time;
  ZWLONG    pt_x, pt_y;
} ZWMSG_;

typedef struct {
  ZWUINT       cbSize;
  ZWUINT       style;
  void        *lpfnWndProc;     /* WNDPROC */
  int          cbClsExtra;
  int          cbWndExtra;
  ZWHINSTANCE_ hInstance;
  void        *hIcon;           /* HICON */
  void        *hCursor;         /* HCURSOR */
  void        *hbrBackground;   /* HBRUSH */
  ZWLPCWSTR_  lpszMenuName;
  ZWLPCWSTR_  lpszClassName;
  void        *hIconSm;         /* HICON */
} ZWWNDCLASSEXW_;

typedef struct { unsigned long Data1; unsigned short Data2, Data3;
                 unsigned char Data4[8]; } ZWIID_;
typedef const ZWIID_ *ZWREFIID_;

/* Win32 functions (externs; symbols live in user32/ole32/kernel32). */
extern ZWHMODULE_   LoadLibraryA(ZWLPCSTR_);
extern void        *GetProcAddress(ZWHMODULE_, ZWLPCSTR_);   /* FARPROC; void* cast below */
extern ZWBOOL      FreeLibrary(ZWHMODULE_);
extern ZWHINSTANCE_ GetModuleHandleW(ZWLPCWSTR_);
extern ZWATOM      RegisterClassExW(const ZWWNDCLASSEXW_ *);
extern ZWHWND_     CreateWindowExW(ZWDWORD, ZWLPCWSTR_, ZWLPCWSTR_, ZWDWORD,
                                   int, int, int, int, ZWHWND_, ZWHMENU_,
                                   ZWHINSTANCE_, void *);
extern ZWBOOL      ShowWindow(ZWHWND_, int);
extern ZWBOOL      UpdateWindow(ZWHWND_);
extern int         GetMessageW(ZWMSG_ *, ZWHWND_, ZWUINT, ZWUINT);
extern ZWBOOL      TranslateMessage(const ZWMSG_ *);
extern ZWLRESULT_  DispatchMessageW(const ZWMSG_ *);
extern ZWLRESULT_  DefWindowProcW(ZWHWND_, ZWUINT, ZWWPARAM_, ZWLPARAM_);
extern void        PostQuitMessage(int);
extern ZWBOOL      GetClientRect(ZWHWND_, ZWRECT_ *);
extern ZWHRESULT   CoInitializeEx(void *, ZWDWORD);
extern void        CoUninitialize(void);
extern int         MultiByteToWideChar(ZWUINT, ZWDWORD, ZWLPCSTR_, int,
                                       ZWLPWSTR_, int);

/* ---- COM interface vtables (consumed) ------------------------------------
 * Unused slots are declared void* (pointer-sized) to preserve layout offsets;
 * only the slots we call carry typed signatures. The compiler never reads
 * these names, so any pointer-sized placeholder keeps the vtable correct. --- */
typedef struct {
  ZWHRESULT (ZW_STDCALL *QueryInterface)(void *, ZWREFIID_, void **);
  ZWULONG   (ZW_STDCALL *AddRef)(void *);
  ZWULONG   (ZW_STDCALL *Release)(void *);
  /* slot 3 */
  ZWHRESULT (ZW_STDCALL *CreateCoreWebView2Controller)(void *, ZWHWND_, void *);
} ZWEnvironmentVtbl_;
typedef struct { const ZWEnvironmentVtbl_ *lpVtbl; } ZWEnvironment_;

typedef struct {
  ZWHRESULT (ZW_STDCALL *QueryInterface)(void *, ZWREFIID_, void **);  /* 0 */
  ZWULONG   (ZW_STDCALL *AddRef)(void *);                              /* 1 */
  ZWULONG   (ZW_STDCALL *Release)(void *);                             /* 2 */
  void *get_IsVisible;                                                 /* 3 */
  ZWHRESULT (ZW_STDCALL *put_IsVisible)(void *, ZWBOOL);               /* 4 */
  void *get_Bounds;                                                    /* 5 */
  ZWHRESULT (ZW_STDCALL *put_Bounds)(void *, ZWRECT_);                 /* 6 */
  void *pad_7, *pad_8, *pad_9, *pad_10, *pad_11, *pad_12,
       *pad_13, *pad_14, *pad_15, *pad_16, *pad_17, *pad_18,
       *pad_19, *pad_20, *pad_21, *pad_22, *pad_23, *pad_24;
  ZWHRESULT (ZW_STDCALL *get_CoreWebView2)(void *, void **);           /* 25 */
} ZWControllerVtbl_;
typedef struct { const ZWControllerVtbl_ *lpVtbl; } ZWController_;

typedef struct {
  ZWHRESULT (ZW_STDCALL *QueryInterface)(void *, ZWREFIID_, void **);  /* 0 */
  ZWULONG   (ZW_STDCALL *AddRef)(void *);                              /* 1 */
  ZWULONG   (ZW_STDCALL *Release)(void *);                             /* 2 */
  void *get_Settings;                                                  /* 3 */
  void *get_Source;                                                    /* 4 */
  ZWHRESULT (ZW_STDCALL *Navigate)(void *, ZWLPCWSTR_);                /* 5 */
} ZWWebViewVtbl_;
typedef struct { const ZWWebViewVtbl_ *lpVtbl; } ZWWebView_;

/* ---- COM handler (implemented by us) --------------------------------------
 * One shape serves both the environment- and controller-completed handlers;
 * Invoke's third arg differs (env ptr vs controller ptr) but is void* here
 * and cast at the call site. No-op QI/AddRef/Release: the loader only QIs for
 * IUnknown + our own interface, returning This/S_OK is correct. No IID
 * constants are needed because we never compare. --------------------------- */
typedef struct {
  ZWHRESULT (ZW_STDCALL *QueryInterface)(void *, ZWREFIID_, void **);
  ZWULONG   (ZW_STDCALL *AddRef)(void *);
  ZWULONG   (ZW_STDCALL *Release)(void *);
  ZWHRESULT (ZW_STDCALL *Invoke)(void *, ZWHRESULT, void *);
} ZWHandlerVtbl_;
typedef struct { const ZWHandlerVtbl_ *lpVtbl; } ZWHandler_;

/* ---- Module state (single-window host) ----------------------------------- */
static ZWHWND_       zwv_hwnd;
static const char   *zwv_url;
static ZWController_ *zwv_controller;
static ZWWebView_    *zwv_webview;

/* ---- Win32 constants (numeric, no #include needed) ----------------------- */
#define ZW_WM_DESTROY          0x0002
#define ZW_WM_SIZE             0x0005
#define ZW_WS_OVERLAPPEDWINDOW 0x00CF0000L
#define ZW_CS_HREDRAW          0x0002
#define ZW_CS_VREDRAW          0x0001
#define ZW_CW_USEDEFAULT       ((int)0x80000000)
#define ZW_SW_SHOW             5
#define ZW_COLOR_WINDOW        5
#define ZW_CP_UTF8             65001
#define ZW_COINIT_APARTMENTTHREADED 0x2

/* ---- Handler implementations --------------------------------------------- */
static ZWHRESULT ZW_STDCALL zw_handler_QI(void *This, ZWREFIID_ riid, void **ppv) {
  (void)riid;
  *ppv = This;
  return 0;  /* S_OK */
}
static ZWULONG ZW_STDCALL zw_handler_AddRef(void *This) { (void)This; return 1; }
static ZWULONG ZW_STDCALL zw_handler_Release(void *This) { (void)This; return 1; }

/* Environment ready: create the controller against our window. The controller
 * is delivered to zw_ctrl_Invoke asynchronously. */
static ZWHRESULT ZW_STDCALL zw_env_Invoke(void *This, ZWHRESULT hr, void *envp) {
  (void)This;
  if (hr < 0 || !envp) return 0;
  static const ZWHandlerVtbl_ ctrlVtbl =
    { zw_handler_QI, zw_handler_AddRef, zw_handler_Release, zw_ctrl_Invoke };
  static ZWHandler_ ctrlHandler = { &ctrlVtbl };
  ZWEnvironment_ *env = (ZWEnvironment_ *)envp;
  env->lpVtbl->CreateCoreWebView2Controller(env, zwv_hwnd, &ctrlHandler);
  return 0;
}

/* Controller ready: size it to the client area, show it, grab the underlying
 * webview, and Navigate to the URL. */
static ZWHRESULT ZW_STDCALL zw_ctrl_Invoke(void *This, ZWHRESULT hr, void *ctrlp) {
  (void)This;
  if (hr < 0 || !ctrlp) return 0;
  ZWController_ *ctrl = (ZWController_ *)ctrlp;
  zwv_controller = ctrl;
  ZWRECT_ r;
  GetClientRect(zwv_hwnd, &r);
  ctrl->lpVtbl->put_Bounds(ctrl, r);            /* fill the window */
  ctrl->lpVtbl->put_IsVisible(ctrl, 1);         /* TRUE */
  ctrl->lpVtbl->get_CoreWebView2(ctrl, (void **)&zwv_webview);
  if (zwv_webview) {
    wchar_t wurl[2048];
    MultiByteToWideChar(ZW_CP_UTF8, 0, zwv_url, -1, wurl, 2048);
    zwv_webview->lpVtbl->Navigate(zwv_webview, wurl);
  }
  return 0;
}

/* ---- WndProc: keep the webview sized to the window; quit on destroy ------ */
static ZWLRESULT_ ZW_STDCALL zw_WndProc(ZWHWND_ hwnd, ZWUINT msg,
                                        ZWWPARAM_ wp, ZWLPARAM_ lp) {
  if (msg == ZW_WM_DESTROY) { PostQuitMessage(0); return 0; }
  if (msg == ZW_WM_SIZE && zwv_controller) {
    ZWRECT_ r;
    GetClientRect(hwnd, &r);
    zwv_controller->lpVtbl->put_Bounds(zwv_controller, r);
  }
  return DefWindowProcW(hwnd, msg, wp, lp);
}

/* ---- Entry: called from WebViewModule.zu's __MINGW32__/_WIN32 branch -----
 * Blocks (message loop) until the window is destroyed, then returns. The
 * caller passes UTF-8 url/title; title is widened for CreateWindowExW. ------ */
static void zimbu_webview2_open(const char *url, const char *title) {
  zwv_url = url;
  zwv_controller = (ZWController_ *)0;
  zwv_webview = (ZWWebView_ *)0;
  zwv_hwnd = (ZWHWND_)0;

  CoInitializeEx((void *)0, ZW_COINIT_APARTMENTTHREADED);

  static const wchar_t kClassName[] = L"ZimbuWebView2";
  ZWHINSTANCE_ hInst = GetModuleHandleW((ZWLPCWSTR_)0);

  ZWWNDCLASSEXW_ wc;
  /* Zero the struct (aggregate zero-init), then set the fields that matter. */
  ZWRECT_ z0 = { 0, 0, 0, 0 };
  (void)z0;
  /* C89/C99: designated init not relied on; field-wise assign after zeroing. */
  {
    unsigned char *p = (unsigned char *)&wc;
    ZWULONG i;
    for (i = 0; i < (ZWULONG)sizeof(wc); ++i) p[i] = 0;
  }
  wc.cbSize        = (ZWUINT)sizeof(wc);
  wc.style         = ZW_CS_HREDRAW | ZW_CS_VREDRAW;
  wc.lpfnWndProc   = (void *)zw_WndProc;
  wc.hInstance     = hInst;
  wc.hbrBackground = (void *)(long)ZW_COLOR_WINDOW;
  wc.lpszClassName = kClassName;
  RegisterClassExW(&wc);

  wchar_t wtitle[512];
  MultiByteToWideChar(ZW_CP_UTF8, 0, title, -1, wtitle, 512);
  zwv_hwnd = CreateWindowExW(0, kClassName, wtitle, ZW_WS_OVERLAPPEDWINDOW,
                             ZW_CW_USEDEFAULT, ZW_CW_USEDEFAULT, 1000, 700,
                             (ZWHWND_)0, (ZWHMENU_)0, hInst, (void *)0);
  ShowWindow(zwv_hwnd, ZW_SW_SHOW);
  UpdateWindow(zwv_hwnd);

  /* Load WebView2Loader.dll and kick off environment creation. The DLL ships
   * next to the exe; the Edge runtime is Evergreen (resolved by the loader). */
  ZWHMODULE_ hLoader = LoadLibraryA("WebView2Loader.dll");
  if (hLoader) {
    void *sym = GetProcAddress(hLoader,
                               "CreateCoreWebView2EnvironmentWithOptions");
    if (sym) {
      ZWHRESULT (ZW_STDCALL *pfn)(ZWLPCWSTR_, ZWLPCWSTR_, void *, void *) =
        (void *)sym;                       /* cast via void* (GCC extension) */
      static const ZWHandlerVtbl_ envVtbl =
        { zw_handler_QI, zw_handler_AddRef, zw_handler_Release, zw_env_Invoke };
      static ZWHandler_ envHandler = { &envVtbl };
      pfn((ZWLPCWSTR_)0, (ZWLPCWSTR_)0, (void *)0, &envHandler);
    }
  }

  /* Message loop: GetMessageW returns >0 while messages flow, 0 on WM_QUIT
   * (posted by WM_DESTROY), <0 on error. Exiting the loop = window closed. */
  ZWMSG_ m;
  while (GetMessageW(&m, (ZWHWND_)0, 0, 0) > 0) {
    TranslateMessage(&m);
    DispatchMessageW(&m);
  }

  if (hLoader) FreeLibrary(hLoader);
  CoUninitialize();
}

#endif /* _WIN32 */
#endif /* ZIMBU_WEBVIEW2_WIN_H */

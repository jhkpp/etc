#include "Window.h"

static Window* g_pWin = NULL;
Window::Window(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) 
    : _wp(NULL), _hInstance(NULL), _w(0), _h(0)
{
    _wp             = WndProc;

    _hInstance      = hInstance;
    _hPrevInstance  = hPrevInstance;
    _pCmdLine       = pCmdLine;
    _nCmdShow       = nCmdShow;
}

Window::~Window(void)
{
}

int Window::Init(LPCWSTR t, int w, int h)
{
    LPCWSTR CLASS_NAME = t;

    _w = w;
    _h = h;

    WNDCLASS wc = { };
    wc.lpfnWndProc      = _wp;
    wc.hInstance        = _hInstance;
    wc.lpszClassName    = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, CLASS_NAME, t, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, _w, _h, NULL, NULL, _hInstance, NULL);
    if (hwnd == NULL)
        return 0;

    ShowWindow(hwnd, _nCmdShow);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnregisterClass(CLASS_NAME, wc.hInstance);

    return 0;
}

void Window::onCreate(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    /*
    _hEdit = CreateWindow(L"EDIT",
        NULL,
        WS_BORDER | WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_LEFT |
        ES_MULTILINE | ES_AUTOVSCROLL,
        0, 0, 0, 0,
        hwnd,
        (HMENU)100,
        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
        NULL);
    */
    _s.Init("127.0.0.1", 7070);
}

void Window::onDestroy(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    PostQuitMessage(0);
}


LRESULT Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_CREATE:     onCreate(hwnd, uMsg, wParam, lParam); return 0;
    case WM_DESTROY:    onDestroy(hwnd, uMsg, wParam, lParam); return 0;
    }
    return 0;
}


LRESULT CALLBACK Window::WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    g_pWin->WindowProc(hwnd, uMsg, wParam, lParam);

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
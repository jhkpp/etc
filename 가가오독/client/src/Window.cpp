#include "Window.h"

Window::Window(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) : _wp(NULL)
{
    _wp             = WindowProc;

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
    const wchar_t CLASS_NAME[] = L"APP";

    _w = w;
    _h = h;

    WNDCLASS wc = { };
    wc.lpfnWndProc      = WindowProc;
    wc.hInstance        = _hInstance;
    wc.lpszClassName    = CLASS_NAME;

    RegisterClass(&wc);


    HWND hwnd = CreateWindowEx(0, CLASS_NAME, t, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, _w, _h, NULL, NULL, _hInstance, NULL);

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, _nCmdShow);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnregisterClass(CLASS_NAME, wc.hInstance);

    return 0;
}


LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_CREATE:
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
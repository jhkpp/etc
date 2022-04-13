#pragma once
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
#include <windows.h>

class Window {
public :
	Window  ( HINSTANCE, HINSTANCE, PWSTR, int );
	~Window ( void );

private:
	static LRESULT CALLBACK WindowProc ( HWND, UINT, WPARAM, LPARAM );

public:
	int Init (LPCWSTR, int, int);


private:
	int								_w, _h;

	WNDPROC							_wp;
	HINSTANCE						_hInstance;
	HINSTANCE						_hPrevInstance;
	PWSTR							_pCmdLine; 
	int								_nCmdShow;

};
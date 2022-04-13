#pragma once
#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
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
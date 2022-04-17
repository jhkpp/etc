#pragma once
#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
#include <windows.h>
#include "Socket.h"

class Window {
public :
	Window  ( HINSTANCE, HINSTANCE, PWSTR, int );
	~Window ( void );

private:
	static LRESULT CALLBACK WndProc ( HWND, UINT, WPARAM, LPARAM );

	LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	int Init (LPCWSTR, int, int);

public:
	void onCreate(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void onDestroy(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);



private:
	int								_w, _h;

	HWND							_hEdit;

	WNDPROC							_wp;
	HINSTANCE						_hInstance;
	HINSTANCE						_hPrevInstance;
	PWSTR							_pCmdLine; 
	int								_nCmdShow;
	Socket							_s;
};
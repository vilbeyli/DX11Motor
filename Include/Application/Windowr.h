#pragma once

#include 

class Window
{
public:
	static Window Create(HINSTANCE hInstance, WNDPROC lpfnWndProc, int iWidth, int iHeight, int nCmdShow);

	int GetHeight() const;
	int GetWidth() const;

private:
	HWND hWnd;
};
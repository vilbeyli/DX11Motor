#pragma once

#include <Windows.h>
#include <string>

struct WindowCreateParams
{
	HINSTANCE hInstance; // Program instance handle
	WNDPROC lpfnWndProc; // Event Handler fonksiyon
	std::wstring strWindowTitle; // Pencere basligi
	int iWidth;          // Pencere genisligi
	int iHeight;         // Pencere uzunlugu
	int iPositionX;      // Pencerenin ekrandaki X koordinati
	int iPositionY;      // Pencerenin ekrandaki Y koordinati
	int nCmdShow;        // pencere gosterim bayragi 
};

class Window
{
public:
	static Window Create(const WindowCreateParams& params);

	void Show() const;
	void Hide() const;
	void Minimize() const;
	void Maximize() const;
	void ToggleFullscreen(bool bFullScreen) const;

private:
	Window() = default;

private:
	HWND hWnd;
};
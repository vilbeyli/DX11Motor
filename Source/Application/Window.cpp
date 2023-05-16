#include "Application/Window.h"

#include <string>

static std::wstring BuildWindowClassName(const std::wstring& WindowTitle)
{
    std::wstring WindowClassName = WindowTitle;
    WindowClassName += L"WindowClass";
    return WindowClassName;
}

Window Window::Create(const WindowCreateParams& params)
{
	Window w;

    // Isletim sisteminin penceremizi takip icin kullandigi WindowClass objesi ve isletim sistemine kaydi (register)
    const std::wstring WindowClassName = BuildWindowClassName(params.strWindowTitle); 
    
    // Bazi WindowClass stilleri: https://learn.microsoft.com/en-us/windows/win32/winmsg/window-class-styles
    // CS_HREDRAW | Pencere boyutunun yatay (horizontal) degisimlerinde tum pencere yeniden cizilir
    // CS_VREDRAW | Pencere boyutunun dikey (vertical  ) degisimlerinde tum pencere yeniden cizilir
    const int iWindowClassStyle = CS_HREDRAW | CS_VREDRAW;

    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);           // Windows API oruntusu: kullandigimiz class'in byte cinsinden boyu belirtilir
    wc.style = iWindowClassStyle;       
    wc.lpfnWndProc = params.lpfnWndProc;      // Pencere event proseduru
    wc.hInstance = params.hInstance;          // Pencereye sahip uygulama instance handle'i
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Fare ikonu handle'i
    wc.lpszClassName = WindowClassName.c_str();
    RegisterClassEx(&wc);
    
    // create & show the window
    const int iWindowStyle = WS_OVERLAPPEDWINDOW;
    RECT wr = { 0, 0, params.iWidth, params.iHeight };
    AdjustWindowRect(&wr, iWindowStyle, FALSE);

    w.hWnd = CreateWindowEx(
        NULL,                          // Pencere stili (genisletilmis)
        WindowClassName.c_str(),       // Pencere class ismi
        params.strWindowTitle.c_str(), // Pencere basligi
        iWindowStyle,                  // Pencere stili
        params.iPositionX,             // Pencerenin ekrandaki X koordinati
        params.iPositionY,             // Pencerenin ekrandaki Y koordinati
        wr.right - wr.left,            // Pencere genisligi
        wr.bottom - wr.top,            // Pencere uzunlugu
        NULL,                          // Ebeveyn pencere
        NULL,                          // Menu handle'i
        params.hInstance,              // Program instance handle'i
        NULL                           // TODO
    );
    
    ShowWindow(w.hWnd, params.nCmdShow);
	return w;
}

void Window::Show() const
{
    ShowWindow(this->hWnd, SW_SHOW);
}
void Window::Hide() const
{
    ShowWindow(this->hWnd, SW_HIDE);
}
void Window::Minimize() const
{
    ShowWindow(this->hWnd, SW_SHOWMINIMIZED);
}
void Window::Maximize() const
{
    ShowWindow(this->hWnd, SW_SHOWMAXIMIZED);
}
void Window::ToggleFullscreen(bool bWindow) const
{

}
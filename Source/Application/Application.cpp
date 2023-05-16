#include "Application/Application.h"

#include "Application/Window.h"

LRESULT CALLBACK Application_MainWindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

bool Application::Initialize(HINSTANCE hInst, int nCmdShow)
{
    WindowCreateParams WindowParams = {};
    WindowParams.iHeight = 600;
    WindowParams.iWidth = 900;
    WindowParams.iPositionX = 100;
    WindowParams.iPositionY = 100;
    WindowParams.hInstance = hInst;
    WindowParams.lpfnWndProc = Application_MainWindowProcedure;
    WindowParams.strWindowTitle = L"DX11Motor";
    WindowParams.nCmdShow = nCmdShow;
    Window wnd = Window::Create(WindowParams);
    
    // test window
    Sleep(1000);
    wnd.Maximize();
    Sleep(1000);
    wnd.Minimize();
    wnd.Show();
    Sleep(1000);
    wnd.Hide();
    Sleep(1000);
    wnd.Show();
    Sleep(1000);

    return true;
}

int Application::Exit()
{
    return EXIT_SUCCESS;
}

void Application::Load()
{
}

void Application::Unload()
{
}

void Application::UpdateAndRender()
{
}


LRESULT CALLBACK Application_MainWindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
}
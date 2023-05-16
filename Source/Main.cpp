#include <Windows.h>

#include "Application/Application.h"

int WINAPI WinMain(
    HINSTANCE hInstance,     // Programimizin instance handle'i
    HINSTANCE hPrevInstance, // [Legacy]
    LPSTR lpCmdLine,         // Command Line parametre string'i
    int nCmdShow             // Uygulamam penceresinin ilk acilista nasil gosterilecegini belirten parametre
)
{
    Application::Initialize(hInstance, nCmdShow);

    Application::Load();

    MSG msg = {};
    while (true) // Main message loop
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                break;
        }
    }

    Application::Unload();

    int iExitCode = Application::Exit();
    return iExitCode;
}

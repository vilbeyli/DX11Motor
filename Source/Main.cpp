#include <Windows.h>

#include "Application/Application.h"

int WINAPI WinMain(
    HINSTANCE hInstance,     // Su anki App instance handle'i
    HINSTANCE hPrevInstance, // Bir onceki App instance handle'i
    LPSTR lpCmdLine,         // Command Line parametre string'i
    int nCmdShow             // Uygulamam penceresinin ilk acilista nasil gosterilecegini belirten parametre
)
{
    Application::Initialize();

    Application::Load();

    // ...

    Application::Unload();

    int iExitCode = Application::Exit();
    return iExitCode;
}

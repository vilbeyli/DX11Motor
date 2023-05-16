#include "Application/Application.h"

#include <Windows.h>

bool Application::Initialize()
{
    // MessageBoxW(
    //     _In_opt_ HWND hWnd,
    //     _In_opt_ LPCWSTR lpText,
    //     _In_opt_ LPCWSTR lpCaption,
    //     _In_ UINT uType);
    MessageBoxW(
        NULL,               // elimizde henuz bir pencere handle'i olmadigi icin NULL
        L"Merhaba!",        // Mesaj kutusunda yazacak olan text
        L"Mesaj Penceresi", // Mesaj penceresinin basligi
        MB_OK | MB_ICONINFORMATION // Mesaj penceresinde olacak tuslar: "OK", kullanilacak ikon "ICONINFORMATION"
    );

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

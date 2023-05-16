#include <Windows.h>

int WINAPI WinMain(
    HINSTANCE hInstance,     // Su anki App instance handle'i
    HINSTANCE hPrevInstance, // Bir onceki App instance handle'i
    LPSTR lpCmdLine,         // Command Line parametre string'i
    int nCmdShow             // Uygulamam penceresinin ilk acilista nasil gosterilecegini belirten parametre
)
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

    return EXIT_SUCCESS;
}

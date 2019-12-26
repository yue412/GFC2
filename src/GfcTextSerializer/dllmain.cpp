#include "GfcTextSerializer.h"

HMODULE g_nDLLHandle = 0;

BOOL WINAPI DllMain(
    _In_ HINSTANCE hinstDLL,
    _In_ DWORD     fdwReason,
    _In_ LPVOID    lpvReserved
)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
        g_nDLLHandle = hinstDLL;
        break;
    default:
        g_nDLLHandle = 0;
        break;
    }
    return TRUE;
}
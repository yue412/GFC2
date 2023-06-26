#include "GfcSchema/Model.h"
#include "GfcEngine/GfcEngineUtils.h"

gfc::schema::CModel* g_pModel = nullptr;

#if (defined _WIN32 || defined _WIN64)

#include "resource.h"
#include <Windows.h>

BOOL WINAPI DllMain(
    _In_ HINSTANCE hinstDLL,
    _In_ DWORD     fdwReason,
    _In_ LPVOID    lpvReserved
)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
    //case DLL_THREAD_ATTACH:
        {
            if (g_pModel == nullptr)
            {
                // 加载资源
                HINSTANCE hInst = hinstDLL;
                HRSRC hRsrc = FindResource(hInst, MAKEINTRESOURCE(IDR_EXP1), L"EXP");
                if (!hRsrc)
                    return FALSE;
                DWORD dwSize = SizeofResource(hInst, hRsrc);
                HGLOBAL hGlobal = LoadResource(hInst, hRsrc);
                LPVOID pBuffer = LockResource(hGlobal);
                BYTE* pByte = new BYTE[dwSize + 1];
                memcpy(pByte, pBuffer, dwSize);
                GlobalUnlock(hGlobal);
                g_pModel = new gfc::schema::CModel;
                // 解析
                gfc::engine::CEngineUtils::loadSchema((char*)pByte, dwSize, g_pModel);
            }
        }
        break;
    case DLL_PROCESS_DETACH:
        delete g_pModel;
        g_pModel = nullptr;
        break;
    }
    return TRUE;
}

#else

void __attribute__((constructor)) gfc_classes_load(void);
void __attribute__((destructor)) gfc_classes_unload(void);

// Called when the library is loaded and before dlopen() returns
void gfc_classes_load(void)
{
    if (g_pModel == nullptr)
    {
        extern char _binary_GFC_exp_start[];
        extern char _binary_GFC_exp_end[];
        int64_t len = _binary_GFC_exp_end - _binary_GFC_exp_start;
        // 加载资源
        g_pModel = new gfc::schema::CModel;
        // 解析
        gfc::engine::CEngineUtils::loadSchema((char*)_binary_GFC_exp_start, len, g_pModel);
    }
}

// Called when the library is unloaded and before dlclose()
// returns
void gfc_classes_unload(void)
{
    delete g_pModel;
    g_pModel = nullptr;
}
#endif
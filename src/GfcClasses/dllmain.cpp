#include <Windows.h>
#include "GfcSchema\Model.h"
#include "GfcEngine\GfcEngineUtils.h"
#include "resource.h"
#include "GfcSchema.h"

gfc::schema::CModel* g_pModel = nullptr;

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
    default:
        delete g_pModel;
        g_pModel = nullptr;
        break;
    }
    return TRUE;
}
#include "TextUpdater.h"
#include <Windows.h>
#include "resource.h"
#include "GfcTextSerializer.h"
#include "glodon\objectbuf\Entity.h"
#include "Scanner.h"
#include "Parser.h"
#include <algorithm>
#include "Common.h"

namespace glodon {
namespace objectbuf {

TextUpdater::~TextUpdater()
{
}

void TextUpdater::init(const std::string & sVersion)
{
    delete m_pDllModel;  m_pDllModel = nullptr;
    delete m_pFileModel; m_pFileModel = nullptr;
    // 相等，不需要升级
    if (_stricmp(sVersion.c_str(), Entity::Version().c_str()) == 0)
        return;
    // Load File model
    auto sSchema = sVersion;
    std::replace(sSchema.begin(), sSchema.end(), '.', 'X');
    loadFileModel(sSchema);
    // Load dll model
    loadDllModel();
}

void TextUpdater::update(std::string & sLine)
{

}

void TextUpdater::loadDllModel()
{
    // 加载资源
    HINSTANCE hInst = g_nDLLHandle;
    HRSRC hRsrc = FindResource(hInst, MAKEINTRESOURCE(IDR_EXP1), L"EXP");
    if (!hRsrc)
        return;
    DWORD dwSize = SizeofResource(hInst, hRsrc);
    HGLOBAL hGlobal = LoadResource(hInst, hRsrc);
    LPVOID pBuffer = LockResource(hGlobal);
    BYTE* pByte = new BYTE[dwSize + 1];
    memcpy(pByte, pBuffer, dwSize);
    GlobalUnlock(hGlobal);
    // 解析
    Scanner oScanner(pByte, dwSize);
    Parser oParser(&oScanner);
    m_pDllModel = new gfc2::schema::CModel;
    oParser.m_pModel = m_pDllModel;
    oParser.Parse();
}

void TextUpdater::loadFileModel(const std::string& sFileSchema)
{
    //
    if (m_sSchemaPath.empty())
        return;
    auto sFileName = toWstring(m_sSchemaPath + "\\" + sFileSchema + ".exp");
    if (!fileExists(sFileName))
        return;
    // 解析
    Scanner oScanner(sFileName.c_str());
    Parser oParser(&oScanner);
    m_pFileModel = new gfc2::schema::CModel;
    oParser.m_pModel = m_pFileModel;
    oParser.Parse();
}

}
}
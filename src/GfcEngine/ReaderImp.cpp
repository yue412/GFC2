#include "GfcEngine/Reader.h"
#include "ContainerImp.h"
#include "ReaderImp.h"
#include "FileMap.h"
#include "Common.h"
#include "GfcSchema/TypeObject.h"
#include "GfcSchema/EntityClass.h"
#include "GfcEngine/GfcEngineUtils.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/EntityUpgrader.h"
#include <algorithm>

GFCENGINE_NAMESPACE_BEGIN

GFCENGINE_IMP_FACTORY(CReaderImp, 0)

CReaderImp::CReaderImp() :  m_pModel(nullptr), m_pFileModel(nullptr), m_pUpgrader(nullptr), m_bUseStaticClass(false)
{
}


CReaderImp::~CReaderImp(void)
{
    close();
}

void CReaderImp::initUpgrader()
{
    if (m_pModel)
    {
        auto sFileVer = readFileVersion();
        if (sFileVer != m_pModel->version())
        {
            // 版本不同，需要升级或降级
            if (!openFileModel(sFileVer))
                return;
            m_pUpgrader = new CEntityUpgrader;
            m_pUpgrader->init(m_pModel, m_pFileModel);
        }
    }
}

void CReaderImp::close()
{
    delete m_pUpgrader; 
    m_pUpgrader = nullptr;
    delete m_pFileModel; 
    m_pFileModel = nullptr;
}

EntityPtr CReaderImp::getEntity(EntityRef nId)
{
    return nullptr;
}

EntityIteratorPtr CReaderImp::getEntities(const std::wstring & sType, bool bIncludeSubType)
{
    return nullptr;
}

EntityIteratorPtr CReaderImp::getIterator()
{
    return nullptr;
}

bool CReaderImp::openFileModel(const std::wstring & sFileVer)
{
    auto sFileVerName = UpperString(sFileVer);
    // 处理GFC3X1算量和设计不一致的情况
    if (sFileVerName == L"GFC3X1")
    {
        auto sProductCode = UpperString(readProductCode());
        if (sProductCode == L"GTJ" || sProductCode == L"GQI" || sProductCode == L"GMP")
        {
            sFileVerName = L"GFC3X1_GMP";
        }
    }
    //
    auto sFileName = getFullPath(m_sSchemaPath + L"/" + sFileVerName + L".exp");
    if (!fileExists(sFileName))
        return false;
    m_pFileModel = new gfc::schema::CModel();
    return CEngineUtils::loadSchema(sFileName, m_pFileModel);
}

bool CReaderImp::needUpdate()
{
    return m_pUpgrader != nullptr;
}

void CReaderImp::log(const std::wstring & sError)
{
    m_oErrors.push_back(sError);
}

gfc::schema::CModel * CReaderImp::schema()
{
    return m_pUpgrader ? m_pFileModel : m_pModel;
}

GFCENGINE_NAMESPACE_END
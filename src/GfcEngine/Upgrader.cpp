#include "Upgrader.h"
#include <Windows.h>
#include <assert.h>
//#include "glodon\objectbuf\Entity.h"
#include "Scanner.h"
#include "Parser.h"
#include <algorithm>
#include "Common.h"
#include "GfcEngine\ModelCompatibility.h"
#include "GfcEngine\ClassCompatibility.h"
#include "GfcEngine\AttributeCompatibility.h"
#include "GfcEngine\Converter.h"
#include "GfcSchema/BuildinType.h"
#include "GfcEngine\Entity.h"
#include "GfcEngine\GfcEngineUtils.h"

GFCENGINE_NAMESPACE_BEGIN

CUpgrader::~CUpgrader()
{
    clear();
}

void CUpgrader::init(gfc::schema::CModel* pModel, gfc::schema::CModel* pFileModel)
{
    clear();
    m_pModel = pModel;
    m_pFileModel = pFileModel;
    if (pModel && pFileModel)
    {
        m_pModelCompatibility = new CModelCompatibility;
        m_pModelCompatibility->init(pFileModel, pModel);
    }
}

CEntity* CUpgrader::update(CEntity* pEntity)
{
    auto pClassCompatibility = m_pModelCompatibility->find(pEntity->entityName());
    if (pClassCompatibility == nullptr)
    {
        // no read
        return nullptr;
    }
    auto pNewEntity = CEngineUtils::createEntity(m_pModel, pEntity->entityName());
    transform(pClassCompatibility, pEntity, pNewEntity);
    return pNewEntity;
}

void CUpgrader::transform(CClassCompatibility* pClassCompatibility, CEntity* pSrcEntity, CEntity* pDestEntity)
{
    for (int i = 0; i < pClassCompatibility->getCount(); i++)
    {
        auto pAttributeCompatibility = pClassCompatibility->getCompatibilityAttribute(i);
        int  nIndex = pAttributeCompatibility->toIndex();
        auto pConverter = pAttributeCompatibility->converter();
        if (nIndex != -1 && pConverter && i < (int)pSrcEntity->getPropCount())
        {
            auto pSrcValue = pSrcEntity->getProps(i)->value();
            auto pDestValue = pDestEntity->getProps(nIndex)->value();
            pConverter->transform(pSrcValue, pDestValue);
        }
    }
}

void CUpgrader::clear()
{
    delete m_pModelCompatibility; m_pModelCompatibility = nullptr;
}

GFCENGINE_NAMESPACE_END
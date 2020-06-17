#include "GfcEngine\EntityUpgrader.h"
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

CEntityUpgrader::~CEntityUpgrader()
{
    clear();
}

void CEntityUpgrader::init(gfc::schema::CModel* pDest, gfc::schema::CModel* pSrc)
{
    clear();
    m_pDestModel = pDest;
    m_pSrcModel = pSrc;
    if (pDest && pSrc)
    {
        m_pModelCompatibility = new CModelCompatibility;
        m_pModelCompatibility->init(pSrc, pDest);
    }
}

CEntity* CEntityUpgrader::update(CEntity* pEntity)
{
    auto pClassCompatibility = m_pModelCompatibility->find(pEntity->entityName());
    if (pClassCompatibility == nullptr)
    {
        pClassCompatibility = m_pModelCompatibility->find(pEntity->getSchema()->getBaseType()->getName());
        if (pClassCompatibility == nullptr)
            return nullptr;
    }
    auto pNewEntity = CEngineUtils::createEntity(m_pDestModel, pEntity->entityName());
    transform(pClassCompatibility, pEntity, pNewEntity);
    return pNewEntity;
}

void CEntityUpgrader::transform(CClassCompatibility* pClassCompatibility, CEntity* pSrcEntity, CEntity* pDestEntity)
{
    if (nullptr == pClassCompatibility)
        return;
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

void CEntityUpgrader::clear()
{
    delete m_pModelCompatibility; m_pModelCompatibility = nullptr;
}

GFCENGINE_NAMESPACE_END
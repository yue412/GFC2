#include "GfcEngine\ClassCompatibility.h"
#include "GfcSchema\EntityClass.h"
#include "GfcSchema\EntityAttribute.h"
#include <algorithm>
#include <assert.h>
#include "GfcEngine\AttributeCompatibility.h"

GFCENGINE_NAMESPACE_BEGIN

CClassCompatibility::~CClassCompatibility(void)
{
    clear();
}

void CClassCompatibility::init(gfc::schema::CTypeObject * pFrom, gfc::schema::CTypeObject * pTo)
{
    clear();
    m_sName = pFrom->getName();
    std::vector<gfc::schema::CAttribute*> oFromAttributeList;
    std::vector<gfc::schema::CAttribute*> oToAttributeList;
    getAttributeList((gfc::schema::CClass*)pFrom->getBaseType(), oFromAttributeList);
    getAttributeList((gfc::schema::CClass*)pTo->getBaseType(), oToAttributeList);
    for each (auto pFromAttrib in oFromAttributeList)
    {
        auto itr = std::find_if(oToAttributeList.begin(), oToAttributeList.end(),
            [pFromAttrib](gfc::schema::CAttribute* pAttrib) {return pFromAttrib->getName() == pAttrib->getName(); });
        gfc::schema::CAttribute* pToAttrib = nullptr;
        int nToIndex = -1; 
        if (itr != oToAttributeList.end())
        {
            pToAttrib = *itr;
            nToIndex = itr - oToAttributeList.begin();
        }
        auto pCompatibility = new CAttributeCompatibility;
        pCompatibility->init(pFromAttrib, pToAttrib, nToIndex);
        m_oList.push_back(pCompatibility);
    }
    for (int i = 0; i < (int)oToAttributeList.size(); ++i)
    {
        auto pToAttrib = oToAttributeList[i];
        auto itr = std::find_if(oFromAttributeList.begin(), oFromAttributeList.end(),
            [pToAttrib](gfc::schema::CAttribute* pAttrib) {return pToAttrib->getName() == pAttrib->getName(); });
        if (itr == oFromAttributeList.end())
        {
            auto pCompatibility = new CAttributeCompatibility;
            pCompatibility->init(nullptr, pToAttrib, i);
            m_oList.push_back(pCompatibility);
        }
    }
}

void CClassCompatibility::getAttributeList(gfc::schema::CClass * pClass, std::vector<gfc::schema::CAttribute*>& oAttributeList)
{
    std::vector<gfc::schema::CClass*> oDerivedChain;
    oDerivedChain.push_back(pClass);
    auto pParent = pClass->getParent();
    while (pParent)
    {
        oDerivedChain.push_back(pParent);
        pParent = pParent->getParent();
    }
    std::for_each(oDerivedChain.rbegin(), oDerivedChain.rend(), 
        [&oAttributeList](gfc::schema::CClass* pClass) {
            for (int i = 0; i < pClass->getAttributeCount(); i++)
            {
                oAttributeList.push_back(pClass->getAttribute(i));
            }
        }
    );
}

void CClassCompatibility::clear()
{
    for each (auto pItem in m_oList)
    {
        delete pItem;
    }
    m_oList.clear();
}

GFCENGINE_NAMESPACE_END
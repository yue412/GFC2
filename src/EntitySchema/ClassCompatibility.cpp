#include "ClassCompatibility.h"
#include "EntityClass.h"
#include "EntityAttribute.h"
#include <algorithm>
#include <assert.h>
#include "AttributeCompatibility.h"

GFC_NAMESPACE_BEGIN

CClassCompatibility::~CClassCompatibility(void)
{
    clear();
}

void CClassCompatibility::init(CClass * pFrom, CClass * pTo)
{
    clear();
    m_sName = pFrom->getName();
    std::vector<CAttribute*> oFromAttributeList;
    std::vector<CAttribute*> oToAttributeList;
    getAttributeList(pFrom, oFromAttributeList);
    getAttributeList(pTo, oToAttributeList);
    for each (auto pFromAttrib in oFromAttributeList)
    {
        auto itr = std::find_if(oToAttributeList.begin(), oToAttributeList.end(),
            [pFromAttrib](CAttribute* pAttrib) {return pFromAttrib->getName() == pAttrib->getName(); });
        auto pToAttrib = itr != oToAttributeList.end() ? *itr : nullptr;
        auto pCompatibility = new CAttributeCompatibility;
        pCompatibility->init(pFromAttrib, pToAttrib);
        m_oList.push_back(pCompatibility);
    }
    for each (auto pToAttrib in oToAttributeList)
    {
        auto itr = std::find_if(oFromAttributeList.begin(), oFromAttributeList.end(),
            [pToAttrib](CAttribute* pAttrib) {return pToAttrib->getName() == pAttrib->getName(); });
        if (itr == oToAttributeList.end())
        {
            auto pCompatibility = new CAttributeCompatibility;
            pCompatibility->init(nullptr, pToAttrib);
            m_oList.push_back(pCompatibility);
        }
    }
}

void CClassCompatibility::getAttributeList(CClass * pClass, std::vector<CAttribute*>& oAttributeList)
{
    std::vector<CClass*> oDerivedChain;
    oDerivedChain.push_back(pClass);
    auto pParent = pClass->getParent();
    while (pParent)
    {
        oDerivedChain.push_back(pParent);
        pParent = pParent->getParent();
    }
    std::for_each(oDerivedChain.rbegin(), oDerivedChain.rend(), 
        [&oAttributeList](CClass* pClass) {
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

GFC_NAMESPACE_END

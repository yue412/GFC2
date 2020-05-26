#include "EntityClass.h"
#include "EntityAttribute.h"
#include <algorithm>

GFC_NAMESPACE_BEGIN

CClass::CClass(): m_pParent(NULL)/*, m_bIsValueType(false)*/, m_bIsAbstract(false), m_bIsValid(true)
{
}

CClass::CClass(const std::wstring &sName): CTypeObject(sName), m_pParent(NULL)/*, m_bIsValueType(false)*/, m_bIsAbstract(false), m_bIsValid(true)
{

}

CClass::~CClass()
{
    for (CAttributeList::iterator itr = m_oAttributeList.begin(); itr != m_oAttributeList.end(); ++itr)
    {
        delete *itr;
    }
}

CClass *CClass::getChild(int nIndex)
{
    _ASSERT(nIndex >= 0 && nIndex < (int)m_oChildList.size());
    return m_oChildList[nIndex];
}

void CClass::addChild(CClass *pClass)
{
    m_oChildList.push_back(pClass);
}

bool CClass::isInherited(const std::wstring & sName)
{
    CClass* pParent = this;
    while (pParent = pParent->getParent())
    {
        if (pParent->getName() == sName)
        {
            return true;
        }
    }
    return false;
}

CAttribute *CClass::getAttribute(int nIndex)
{
    _ASSERT(nIndex >= 0 && nIndex < (int)m_oAttributeList.size());
    return m_oAttributeList[nIndex];
}

void CClass::addAttribute(CAttribute *pAttribute)
{
    m_oAttributeList.push_back(pAttribute);
}

CAttribute * CClass::findAttribute(const std::wstring & sName)
{
    auto itr = std::find_if(m_oAttributeList.begin(), m_oAttributeList.end(),
        [sName](CAttribute* pAttrib) { return pAttrib->getName() == sName; });
    return itr == m_oAttributeList.end() ? nullptr : *itr;
}

int CClass::attributeIndexByName(const std::wstring & sName)
{
    auto itr = std::find_if(m_oAttributeList.begin(), m_oAttributeList.end(),
        [sName](CAttribute* pAttrib) { return pAttrib->getName() == sName; });
    return itr == m_oAttributeList.end() ? -1 : itr-m_oAttributeList.begin();
}

GFC_NAMESPACE_END
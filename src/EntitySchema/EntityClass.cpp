#include "EntityClass.h"
#include "EntityAttribute.h"
#include <algorithm>

GFC_NAMESPACE_BEGIN

CClass::CClass(): m_pParent(NULL)/*, m_bIsValueType(false)*/, m_bIsAbstract(false), m_bIsValid(true), m_nDataSize(-1)
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

GFC_NAMESPACE_END
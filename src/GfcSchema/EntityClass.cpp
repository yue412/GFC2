#include "GfcSchema\EntityClass.h"
#include "GfcSchema\EntityAttribute.h"
#include <algorithm>
#include <assert.h>

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
    assert(nIndex >= 0 && nIndex < (int)m_oAttributeList.size());
    return m_oAttributeList[nIndex];
}

int CClass::getTotalAttributeCount()
{
    int nTotal = 0;
    auto pClass = this;
    while (pClass)
    {
        nTotal += pClass->getAttributeCount();
        pClass = pClass->getParent();
    }
    return nTotal;
}

void CClass::addAttribute(CAttribute *pAttribute)
{
    assert(pAttribute);
    auto itr = m_oAttributeMap.find(pAttribute->getName());
    if (itr == m_oAttributeMap.end())
    {
        m_oAttributeList.push_back(pAttribute);
        m_oAttributeMap.insert(std::make_pair(pAttribute->getName(), m_oAttributeList.size() - 1));
    }
    else
    {
        assert(false);
    }
}

CAttribute * CClass::findAttribute(const std::wstring & sName)
{
    auto nIndex = attributeIndexByName(sName);
    return nIndex >= 0 ? getAttribute(nIndex) : nullptr;
}

int CClass::attributeIndexByName(const std::wstring & sName)
{
    auto itr = m_oAttributeMap.find(sName);
    if (itr != m_oAttributeMap.end())
        return (int)itr->second;
    else
        return -1;
}

GFC_NAMESPACE_END
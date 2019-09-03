#include "class.h"
#include "attribute.h"

CClass::CClass(): m_pParent(NULL)/*, m_bIsValueType(false)*/, m_bIsAbstract(false)
{
}

CClass::CClass(const std::wstring &sName): CTypeObject(sName), m_pParent(NULL)/*, m_bIsValueType(false)*/, m_bIsAbstract(false)
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

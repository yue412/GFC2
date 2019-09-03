#include "enumtype.h"

CEnumType::CEnumType()
{
}

CEnumType::CEnumType(const std::wstring &sName): CTypeObject(sName)
{

}

std::wstring &CEnumType::getEnum(int nIndex)
{
    _ASSERT(nIndex >= 0 && nIndex < (int)m_oEnumList.size());
    return m_oEnumList[nIndex];
}

void CEnumType::addEnum(const std::wstring &sEnum)
{
    m_oEnumList.push_back(sEnum);
}

#include "EnumType.h"

GFC_NAMESPACE_BEGIN

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

std::wstring & CEnumType::getEnumDocument(int nIndex)
{
    return m_oEnumDocumentList[nIndex];
}

void CEnumType::addEnum(const std::wstring &sEnum, const std::wstring& sDocument)
{
    m_oEnumList.push_back(sEnum);
    m_oEnumDocumentList.push_back(sDocument);
}

GFC_NAMESPACE_END

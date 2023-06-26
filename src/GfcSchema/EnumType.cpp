#include "GfcSchema/EnumType.h"
#include <algorithm>
#include <assert.h>

GFC_NAMESPACE_BEGIN

CEnumType::CEnumType()
{
}

CEnumType::CEnumType(const std::wstring &sName): CTypeObject(sName)
{

}

std::wstring &CEnumType::getEnum(int nIndex)
{
    assert(nIndex >= 0 && nIndex < (int)m_oEnumList.size());
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

bool CEnumType::exists(const std::wstring & sEnum)
{
    return indexOf(sEnum) != -1;
}

int CEnumType::indexOf(const std::wstring & sEnum)
{
    auto itr = std::find(m_oEnumList.begin(), m_oEnumList.end(), sEnum);
    return itr == m_oEnumList.end() ? -1 : (int)(itr - m_oEnumList.begin());
}

GFC_NAMESPACE_END

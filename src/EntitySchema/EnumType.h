#ifndef ENUMTYPE_H
#define ENUMTYPE_H

#include <vector>
#include "TypeObject.h"

GFC_NAMESPACE_BEGIN

class CEnumType : public CTypeObject
{
public:
    CEnumType();
    CEnumType(const std::wstring& sName);
    virtual CTypeObjectEnum getType() const {return TOE_ENUM;}
    // Ã¶¾ÙÖµ
    std::wstring& getEnum(int nIndex);
    std::wstring& getEnumDocument(int nIndex);
    int getEnumCount(){return (int)m_oEnumList.size();}
    void addEnum(const std::wstring& sEnum, const std::wstring& sDocument);
    bool exists(const std::wstring& sEnum);
    int indexOf(const std::wstring& sEnum);
private:
    std::vector<std::wstring> m_oEnumList;
    std::vector<std::wstring> m_oEnumDocumentList;
};

GFC_NAMESPACE_END

#endif // ENUMTYPE_H

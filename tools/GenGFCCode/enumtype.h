#ifndef ENUMTYPE_H
#define ENUMTYPE_H

#include <vector>
#include "typeobject.h"

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
private:
    std::vector<std::wstring> m_oEnumList;
    std::vector<std::wstring> m_oEnumDocumentList;
};

#endif // ENUMTYPE_H

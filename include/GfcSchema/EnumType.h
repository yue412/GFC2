#ifndef ENUMTYPE_H
#define ENUMTYPE_H

#include <vector>
#include "GfcSchema/TypeObject.h"

GFC_NAMESPACE_BEGIN

class GFCSCHEMA_API CEnumType : public CTypeObject
{
public:
    CEnumType();
    CEnumType(const std::wstring& sName);
    virtual CTypeObjectEnum getType() const {return TOE_ENUM;}
    virtual CDataTypeEnum getDataType() const { return EDT_ENUM; }
    // 枚举值
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

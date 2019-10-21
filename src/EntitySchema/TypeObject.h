#ifndef TYPEOBJECT_H
#define TYPEOBJECT_H

#include <string>
#include "SchemaMacro.h"

GFC_NAMESPACE_BEGIN

enum CTypeObjectEnum
{
    TOE_BUILDIN,
    TOE_TYPE,
    TOE_ENUM,
    TOE_CLASS
};

class CTypeObject
{
public:
    CTypeObject();
    CTypeObject(const std::wstring& sName);
    virtual ~CTypeObject() {}
    std::wstring getName() const {return m_sName;}
    void SetName(const std::wstring& sName) {m_sName = sName;}
    virtual CTypeObjectEnum getType() const = 0;
    virtual bool getIsValueType();
    virtual CTypeObject* getBaseType();
    std::wstring getDocument() { return m_sDocument; }
    void setDocument(const std::wstring& sDocument) { m_sDocument = sDocument; }
private:
    std::wstring m_sName;
    std::wstring m_sDocument;
};

bool lessTypeObject(CTypeObject* type1, CTypeObject* type2);

GFC_NAMESPACE_END

#endif // TYPEOBJECT_H

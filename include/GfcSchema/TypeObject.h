#ifndef TYPEOBJECT_H
#define TYPEOBJECT_H

#include <string>
#include "GfcSchema/SchemaMacro.h"

GFC_NAMESPACE_BEGIN

enum CTypeObjectEnum
{
    TOE_UNDEFINE,
    TOE_BUILDIN,
    TOE_TYPE,
    TOE_ENUM,
    TOE_CLASS
};


enum CDataTypeEnum
{
    EDT_UNKONWN,
    EDT_BOOLEAN,
    EDT_INTEGER,
    EDT_DOUBLE,
    EDT_STRING,
    EDT_ENUM,
    EDT_ENTITY
};


class GFCSCHEMA_API CTypeObject
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
    virtual CDataTypeEnum getDataType() const;
    std::wstring getDocument() { return m_sDocument; }
    void setDocument(const std::wstring& sDocument) { m_sDocument = sDocument; }
private:
    std::wstring m_sName;
    std::wstring m_sDocument;
};

bool GFCSCHEMA_API lessTypeObject(CTypeObject* type1, CTypeObject* type2);

GFC_NAMESPACE_END

#endif // TYPEOBJECT_H

#ifndef BUILDINTYPE_H
#define BUILDINTYPE_H

#include "GfcSchema\TypeObject.h"

GFC_NAMESPACE_BEGIN

class GFCSCHEMA_API CBuildinType : public CTypeObject
{
public:
    CBuildinType();
    CBuildinType(const std::wstring& sName);
    virtual CTypeObjectEnum getType() const {return TOE_BUILDIN;}
    virtual CDataTypeEnum getDataType() const = 0;
};

class GFCSCHEMA_API CBooleanType : public CBuildinType
{
public:
    CBooleanType() : CBuildinType(L"BOOLEAN") {}
    virtual CDataTypeEnum getDataType() const { return EDT_BOOLEAN; }
};

class GFCSCHEMA_API CIntegerType : public CBuildinType
{
public:
    CIntegerType() : CBuildinType(L"INTEGER") {}
    virtual CDataTypeEnum getDataType() const { return EDT_INTEGER; }
};

class GFCSCHEMA_API CRealType : public CBuildinType
{
public:
    CRealType() : CBuildinType(L"REAL") {}
    virtual CDataTypeEnum getDataType() const { return EDT_DOUBLE; }
};

class GFCSCHEMA_API CStringType : public CBuildinType
{
public:
    CStringType() : CBuildinType(L"STRING") {}
    virtual CDataTypeEnum getDataType() const { return EDT_STRING; }
};

GFC_NAMESPACE_END

#endif // BUILDINTYPE_H

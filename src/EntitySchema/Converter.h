#ifndef CONVERTER_H
#define CONVERTER_H

#include "SchemaMacro.h"
#include <string>
#include "AttributeValue.h"

GFC_NAMESPACE_BEGIN

class CEnumType;
class CTypeObject;

// ‘»Œ¡¥
class CConverter
{
public:
    CConverter() : m_pNext(nullptr), m_pFrom(nullptr), m_pTo(nullptr) {}
    virtual ~CConverter();
    virtual void transform(CAttributeValuePtr& pValue);
    virtual void doTransform(CAttributeValuePtr& pValue) = 0;
    virtual CConverter* clone() = 0;
    void setNext(CConverter* pNext);
    void init(CTypeObject* pFrom, CTypeObject* pTo);
protected:
    std::wstring intToEnum(int nIndex);
    int enumToInt(const std::wstring& sValue);
    std::wstring intToBool(int nIndex);
    int boolToInt(const std::wstring & sValue);

    std::wstring enclosedInQuotes(const std::wstring& sValue);
    std::wstring enclosedInDot(const std::wstring& sValue);
    std::wstring enclosedInBrackets(const std::wstring& sValue);
    std::wstring dropDot(const std::wstring& sValue);
    CConverter* m_pNext;
    CTypeObject* m_pFrom;
    CTypeObject* m_pTo;
};

class CCopyConverter: public CConverter
{
public:
    virtual void doTransform(CAttributeValuePtr& pValue);
    virtual CConverter* clone() { return new CCopyConverter(*this); }
};

class CEmptyConverter : public CConverter
{
public:
    virtual void doTransform(CAttributeValuePtr& pValue);
    virtual CConverter* clone() { return new CEmptyConverter(*this); }
};

class CBoolToIntConverter : public CConverter
{
public:
    virtual void doTransform(CAttributeValuePtr& pValue);
    virtual CConverter* clone() { return new CBoolToIntConverter(*this); }
};

class CBoolToStringConverter : public CConverter
{
public:
    virtual void doTransform(CAttributeValuePtr& pValue);
    virtual CConverter* clone() { return new CBoolToStringConverter(*this); }
};

class CBoolToEnumConverter : public CConverter
{
public:
    virtual void doTransform(CAttributeValuePtr& pValue);
    virtual CConverter* clone() { return new CBoolToEnumConverter(*this); }
};

class CIntToBoolConverter : public CConverter
{
public:
    virtual void doTransform(CAttributeValuePtr& pValue);
    virtual CConverter* clone() { return new CIntToBoolConverter(*this); }
};

class CStringConverter : public CConverter
{
public:
    virtual void doTransform(CAttributeValuePtr& pValue);
    virtual CConverter* clone() { return new CStringConverter(*this); }
};

class CIntToEnumConverter : public CConverter
{
public:
    virtual void doTransform(CAttributeValuePtr& pValue);
    virtual CConverter* clone() { return new CIntToEnumConverter(*this); }
};

class CEnumToBoolConverter : public CConverter
{
public:
    virtual void doTransform(CAttributeValuePtr& pValue);
    virtual CConverter* clone() { return new CEnumToBoolConverter(*this); }
};

class CEnumToIntConverter : public CConverter
{
public:
    virtual void doTransform(CAttributeValuePtr& pValue);
    virtual CConverter* clone() { return new CEnumToIntConverter(*this); }
};

class CEnumToStringConverter : public CConverter
{
public:
    virtual void doTransform(CAttributeValuePtr& pValue);
    virtual CConverter* clone() { return new CEnumToStringConverter(*this); }
};

class CEnumConverter : public CConverter
{
public:
    virtual void doTransform(CAttributeValuePtr& pValue);
    virtual CConverter* clone() { return new CEnumConverter(*this); }
};

// multi

class CArrayToOneConverter : public CConverter
{
public:
    virtual void transform(CAttributeValuePtr& pValue);
    virtual void doTransform(CAttributeValuePtr& pValue);
    virtual CConverter* clone() { return new CArrayToOneConverter(*this); }
};

class COneToArrayConverter : public CConverter
{
public:
    virtual void transform(CAttributeValuePtr& pValue);
    virtual void doTransform(CAttributeValuePtr& pValue);
    virtual CConverter* clone() { return new COneToArrayConverter(*this); }
};

class CArrayToArrayConverter: public CConverter
{
public:
    virtual void transform(CAttributeValuePtr& pValue);
    virtual void doTransform(CAttributeValuePtr& pValue);
    virtual CConverter* clone() { return new CArrayToArrayConverter(*this); }
};

class COptionalConverter : public CConverter
{
public:
    virtual void transform(CAttributeValuePtr& pValue);
    virtual void doTransform(CAttributeValuePtr& pValue);
    virtual CConverter* clone() { return new COptionalConverter(*this); }
};


GFC_NAMESPACE_END

#endif // !CONVERTER_H

#ifndef CONVERTER_H
#define CONVERTER_H

#include "SchemaMacro.h"
#include <string>

GFC_NAMESPACE_BEGIN

class CEnumType;
class CTypeObject;

// ‘»Œ¡¥
class CConverter
{
public:
    CConverter() : m_pNext(nullptr), m_pFrom(nullptr), m_pTo(nullptr) {}
    virtual ~CConverter();
    virtual void transform(std::wstring& sValue);
    virtual void doTransform(std::wstring& sValue) = 0;
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
    virtual void doTransform(std::wstring& sValue);
};

class CEmptyConverter : public CConverter
{
public:
    virtual void doTransform(std::wstring& sValue);
};

class CBoolToIntConverter : public CConverter
{
public:
    virtual void doTransform(std::wstring& sValue);
};

class CBoolToStringConverter : public CConverter
{
public:
    virtual void doTransform(std::wstring& sValue);
};

class CBoolToEnumConverter : public CConverter
{
public:
    virtual void doTransform(std::wstring& sValue);
};

class CIntToBoolConverter : public CConverter
{
public:
    virtual void doTransform(std::wstring& sValue);
};

class CStringConverter : public CConverter
{
public:
    virtual void doTransform(std::wstring& sValue);
};

class CIntToEnumConverter : public CConverter
{
public:
    virtual void doTransform(std::wstring& sValue);
};

class CEnumToBoolConverter : public CConverter
{
public:
    virtual void doTransform(std::wstring& sValue);
};

class CEnumToIntConverter : public CConverter
{
public:
    virtual void doTransform(std::wstring& sValue);
};

class CEnumToStringConverter : public CConverter
{
public:
    virtual void doTransform(std::wstring& sValue);
};

class CEnumConverter : public CConverter
{
public:
    virtual void doTransform(std::wstring& sValue);
};

// multi

class CArrayToOneConverter : public CConverter
{
public:
    virtual void transform(std::wstring& sValue);
    virtual void doTransform(std::wstring& sValue);
};

class COneToArrayConverter : public CConverter
{
public:
    virtual void transform(std::wstring& sValue);
    virtual void doTransform(std::wstring& sValue);
};

class CArrayToArrayConverter: public CConverter
{
public:
    virtual void transform(std::wstring& sValue);
    virtual void doTransform(std::wstring& sValue);
};

class COptionalConverter : public CConverter
{
public:
    virtual void transform(std::wstring& sValue);
    virtual void doTransform(std::wstring& sValue);
};


GFC_NAMESPACE_END

#endif // !CONVERTER_H

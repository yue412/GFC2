#ifndef CONVERTER_H
#define CONVERTER_H

#include "GfcEngine\GfcEngine.h"
#include <string>
//#include "AttributeValue.h"

namespace gfc {
    namespace schema {
        class CEnumType;
        class CTypeObject;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class PropValue;

// ‘»Œ¡¥
class CConverter
{
public:
    CConverter() : m_pNext(nullptr), m_pFrom(nullptr), m_pTo(nullptr) {}
    virtual ~CConverter();
    virtual void transform(PropValue* pFrom, PropValue* pTo);
    virtual void doTransform(PropValue* pFrom, PropValue* pTo) = 0;
    virtual CConverter* clone() = 0;
    void setNext(CConverter* pNext);
    void init(gfc::schema::CTypeObject* pFrom, gfc::schema::CTypeObject* pTo);
protected:
    CConverter* m_pNext;
    gfc::schema::CTypeObject* m_pFrom;
    gfc::schema::CTypeObject* m_pTo;
};

class CEmptyConverter : public CConverter
{
public:
    virtual void doTransform(PropValue* pFrom, PropValue* pTo);
    virtual CConverter* clone() { return new CEmptyConverter(*this); }
};

class CBoolToStringConverter : public CConverter
{
public:
    virtual void doTransform(PropValue* pFrom, PropValue* pTo);
    virtual CConverter* clone() { return new CBoolToStringConverter(*this); }
};

class CIntToStringConverter : public CConverter
{
public:
    virtual void doTransform(PropValue* pFrom, PropValue* pTo);
    virtual CConverter* clone() { return new CIntToStringConverter(*this); }
};

class CEntityRefConverter : public CConverter
{
public:
    virtual void doTransform(PropValue* pFrom, PropValue* pTo);
    virtual CConverter* clone() { return new CEntityRefConverter(*this); }
};

class CIntConverter : public CConverter
{
public:
    virtual void doTransform(PropValue* pFrom, PropValue* pTo);
    virtual CConverter* clone() { return new CIntConverter(*this); }
};

class CFloatConverter : public CConverter
{
public:
    virtual void doTransform(PropValue* pFrom, PropValue* pTo);
    virtual CConverter* clone() { return new CFloatConverter(*this); }
};

class CFloatToStringConverter : public CConverter
{
public:
    virtual void doTransform(PropValue* pFrom, PropValue* pTo);
    virtual CConverter* clone() { return new CFloatToStringConverter(*this); }
};

class CStringConverter : public CConverter
{
public:
    virtual void doTransform(PropValue* pFrom, PropValue* pTo);
    virtual CConverter* clone() { return new CStringConverter(*this); }
};

class CIntToEnumConverter : public CConverter
{
public:
    virtual void doTransform(PropValue* pFrom, PropValue* pTo);
    virtual CConverter* clone() { return new CIntToEnumConverter(*this); }
};

class CEnumConverter : public CConverter
{
public:
    virtual void doTransform(PropValue* pFrom, PropValue* pTo);
    virtual CConverter* clone() { return new CEnumConverter(*this); }
};

// multi

class CArrayToOneConverter : public CConverter
{
public:
    virtual void transform(PropValue* pFrom, PropValue* pTo);
    virtual void doTransform(PropValue* pFrom, PropValue* pTo);
    virtual CConverter* clone() { return new CArrayToOneConverter(*this); }
};

class COneToArrayConverter : public CConverter
{
public:
    virtual void transform(PropValue* pFrom, PropValue* pTo);
    virtual void doTransform(PropValue* pFrom, PropValue* pTo);
    virtual CConverter* clone() { return new COneToArrayConverter(*this); }
};

class CArrayToArrayConverter: public CConverter
{
public:
    virtual void transform(PropValue* pFrom, PropValue* pTo);
    virtual void doTransform(PropValue* pFrom, PropValue* pTo);
    virtual CConverter* clone() { return new CArrayToArrayConverter(*this); }
};

class COptionalConverter : public CConverter
{
public:
    virtual void transform(PropValue* pFrom, PropValue* pTo);
    virtual void doTransform(PropValue* pFrom, PropValue* pTo);
    virtual CConverter* clone() { return new COptionalConverter(*this); }
};


GFCENGINE_NAMESPACE_END

#endif // !CONVERTER_H

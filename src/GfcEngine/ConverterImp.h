#ifndef CONVERTERIMP_H
#define CONVERTERIMP_H

#include "GfcEngine/Converter.h"

GFCENGINE_NAMESPACE_BEGIN

class CEmptyConverter : public CConverter
{
public:
    virtual void doTransform(CPropValue* pFrom, CPropValue* pTo);
    virtual CConverter* clone() { return new CEmptyConverter(*this); }
};

class CBoolToStringConverter : public CConverter
{
public:
    virtual void doTransform(CPropValue* pFrom, CPropValue* pTo);
    virtual CConverter* clone() { return new CBoolToStringConverter(*this); }
};

class CIntToStringConverter : public CConverter
{
public:
    virtual void doTransform(CPropValue* pFrom, CPropValue* pTo);
    virtual CConverter* clone() { return new CIntToStringConverter(*this); }
};

class CIntConverter : public CConverter
{
public:
    virtual void doTransform(CPropValue* pFrom, CPropValue* pTo);
    virtual CConverter* clone() { return new CIntConverter(*this); }
};

class CFloatConverter : public CConverter
{
public:
    virtual void doTransform(CPropValue* pFrom, CPropValue* pTo);
    virtual CConverter* clone() { return new CFloatConverter(*this); }
};

class CFloatToStringConverter : public CConverter
{
public:
    virtual void doTransform(CPropValue* pFrom, CPropValue* pTo);
    virtual CConverter* clone() { return new CFloatToStringConverter(*this); }
};

class CStringConverter : public CConverter
{
public:
    virtual void doTransform(CPropValue* pFrom, CPropValue* pTo);
    virtual CConverter* clone() { return new CStringConverter(*this); }
};

class CIntToEnumConverter : public CConverter
{
public:
    virtual void doTransform(CPropValue* pFrom, CPropValue* pTo);
    virtual CConverter* clone() { return new CIntToEnumConverter(*this); }
};

class CEnumConverter : public CConverter
{
public:
    virtual void doTransform(CPropValue* pFrom, CPropValue* pTo);
    virtual CConverter* clone() { return new CEnumConverter(*this); }
};

// multi

class CArrayToOneConverter : public CConverter
{
public:
    virtual void transform(CPropValue* pFrom, CPropValue* pTo);
    virtual void doTransform(CPropValue* pFrom, CPropValue* pTo);
    virtual CConverter* clone() { return new CArrayToOneConverter(*this); }
};

class COneToArrayConverter : public CConverter
{
public:
    virtual void transform(CPropValue* pFrom, CPropValue* pTo);
    virtual void doTransform(CPropValue* pFrom, CPropValue* pTo);
    virtual CConverter* clone() { return new COneToArrayConverter(*this); }
};

class CArrayToArrayConverter: public CConverter
{
public:
    virtual void transform(CPropValue* pFrom, CPropValue* pTo);
    virtual void doTransform(CPropValue* pFrom, CPropValue* pTo);
    virtual CConverter* clone() { return new CArrayToArrayConverter(*this); }
};

class COptionalConverter : public CConverter
{
public:
    virtual void doTransform(CPropValue* pFrom, CPropValue* pTo);
    virtual CConverter* clone() { return new COptionalConverter(*this); }
};

GFCENGINE_NAMESPACE_END

#endif // !CONVERTER_H

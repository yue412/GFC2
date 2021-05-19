#ifndef ATTRIBUTEVALUE_H
#define ATTRIBUTEVALUE_H

#include <string>
#include <vector>
#include <memory>
#include <assert.h>
#include "GfcEngine\GfcEngine.h"

GFCENGINE_NAMESPACE_BEGIN

//class PropValue;

//typedef std::shared_ptr<PropValue> CAttributeValuePtr;

class CEntity;

class GFCENGINE_API CPropValue
{
public:
    CPropValue();
    virtual ~CPropValue();
public:
    virtual bool isNull() const = 0;
    virtual CPropValue* clone() const = 0;
    virtual void assign(CPropValue* pValue) = 0;

    virtual std::wstring asString() const;
    virtual int asInteger() const;
    virtual double asDouble() const;
    virtual bool asBoolean() const;
    virtual EntityRef asEntityRef() const;

    virtual void setAsString(const std::wstring& sValue);
    virtual void setAsInteger(const int& nValue);
    virtual void setAsDouble(const double& dValue);
    virtual void setAsBoolean(const bool& bValue);
    virtual void setAsEntityRef(const EntityRef& nValue);
    virtual std::wstring toString() const;
public:
    virtual void add(CPropValue* pValue) {}
    virtual int getCount() const { return 0; }
    virtual CPropValue* getItems(int nIndex) const { return nullptr; }
    virtual void setItems(int nIndex, CPropValue* pValue) {}
    virtual void clear() {}
protected:
    virtual std::wstring innerToString() const { return L""; }
};

class GFCENGINE_API CLeafPropValue : public CPropValue
{
public:
    CLeafPropValue() : m_bIsNull(true) {}
    virtual bool isNull() const { return m_bIsNull; }
protected:
    void setIsNull(bool bIsNull) { m_bIsNull = bIsNull; }
private:
    bool m_bIsNull;
};

class GFCENGINE_API CCompositePropValue : public CPropValue
{
public:
    CCompositePropValue();
    virtual ~CCompositePropValue();
public:
    virtual bool isNull() const { return getCount() == 0; }
    virtual void add(CPropValue* pValue);
    virtual int getCount() const { return (int)m_oList.size(); }
    virtual CPropValue* getItems(int nIndex) const;
    virtual void setItems(int nIndex, CPropValue* pValue);
    virtual void clear();
    virtual CPropValue* clone() const;
    virtual void assign(CPropValue* pValue);
protected:
    virtual std::wstring innerToString() const;
private:
    bool inRange(int nIndex) const;
    std::vector<CPropValue*> m_oList;
};

class GFCENGINE_API CBooleanValue : public CLeafPropValue
{
public:
    CBooleanValue() : m_bValue(false) { }
    CBooleanValue(bool bValue) : m_bValue(bValue) { setIsNull(false); }
public:
    //virtual std::string asString() const;
    virtual int asInteger() const;
    virtual double asDouble() const;
    virtual bool asBoolean() const;

    //virtual void setAsString(const std::string& sValue);
    virtual void setAsInteger(const int& nValue);
    virtual void setAsBoolean(const bool& bValue);
    virtual CPropValue* clone() const { return new CBooleanValue(m_bValue); }
    virtual void assign(CPropValue* pValue) {assert(pValue); setAsInteger(pValue->asInteger()); }
protected:
    virtual std::wstring innerToString() const;
private:
    bool m_bValue;
};

class GFCENGINE_API CIntegerValue : public CLeafPropValue
{
public:
    CIntegerValue() : m_nValue(0){ }
    CIntegerValue(int nValue) : m_nValue(nValue) { setIsNull(false); }
public:
    //virtual std::string asString() const;
    virtual int asInteger() const;
    virtual double asDouble() const;
    virtual bool asBoolean() const;

    //virtual void setAsString(const std::string& sValue);
    virtual void setAsInteger(const int& nValue);
    virtual void setAsBoolean(const bool& bValue);
    virtual CPropValue* clone() const { return new CIntegerValue(m_nValue); }
    virtual void assign(CPropValue* pValue) { assert(pValue); setAsInteger(pValue->asInteger()); }
protected:
    virtual std::wstring innerToString() const;
private:
    int m_nValue;
};

class GFCENGINE_API CDoubleValue : public CLeafPropValue
{
public:
    CDoubleValue() : m_dValue(0.0) { }
    CDoubleValue(double dValue) : m_dValue(dValue) { setIsNull(false); }
public:
    //virtual std::string asString() const;
    virtual double asDouble() const;

    //virtual void setAsString(const std::string& sValue);
    virtual void setAsInteger(const int& nValue);
    virtual void setAsDouble(const double& dValue);
    virtual void setAsBoolean(const bool& bValue);
    virtual CPropValue* clone() const { return new CDoubleValue(m_dValue); }
    virtual void assign(CPropValue* pValue) { assert(pValue); setAsDouble(pValue->asDouble()); }
protected:
    virtual std::wstring innerToString() const;
private:
    double m_dValue;
};

class GFCENGINE_API CStringValue : public CLeafPropValue
{
public:
    CStringValue() { }
    CStringValue(const std::wstring& sValue): m_sValue(sValue) { setIsNull(false); }
public:
    virtual std::wstring asString() const;

    virtual void setAsString(const std::wstring& sValue);
    //virtual void setAsInteger(const int& nValue);
    //virtual void setAsDouble(const double& dValue);
    //virtual void setAsBoolean(const bool& bValue);
    virtual CPropValue* clone() const { return new CStringValue(m_sValue); }
    virtual void assign(CPropValue* pValue) { assert(pValue); setAsString(pValue->asString()); }
protected:
    virtual std::wstring innerToString() const;
private:
    std::wstring m_sValue;
};

class GFCENGINE_API CEntityRefValue : public CLeafPropValue
{
public:
    CEntityRefValue() : m_nValue(-1) { }
    CEntityRefValue(EntityRef nValue) : m_nValue(nValue) { setIsNull(false); }
public:
    virtual EntityRef asEntityRef() const;

    virtual void setAsEntityRef(const EntityRef& nValue);
    virtual CPropValue* clone() const { return new CEntityRefValue(m_nValue); }
    virtual void assign(CPropValue* pValue) { assert(pValue); setAsEntityRef(pValue->asEntityRef()); }
protected:
    virtual std::wstring innerToString() const;
private:
    EntityRef m_nValue;
};

GFCENGINE_NAMESPACE_END

#endif // !ATTRIBUTEVALUE_H
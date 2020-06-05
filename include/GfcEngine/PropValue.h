#ifndef ATTRIBUTEVALUE_H
#define ATTRIBUTEVALUE_H

#include <string>
#include <vector>
#include <memory>
#include "GfcEngine\GfcEngine.h"

GFCENGINE_NAMESPACE_BEGIN

//class PropValue;

//typedef std::shared_ptr<PropValue> CAttributeValuePtr;

class Entity;

class GFCENGINE_API PropValue
{
public:
    PropValue();
    virtual ~PropValue();
public:
    virtual bool isNull() const = 0;

    virtual std::string asString() const;
    virtual int asInteger() const;
    virtual double asDouble() const;
    virtual bool asBoolean() const;
    virtual EntityRef asEntityRef() const;

    virtual void setAsString(const std::string& sValue);
    virtual void setAsInteger(const int& nValue);
    virtual void setAsDouble(const double& dValue);
    virtual void setAsBoolean(const bool& bValue);
    virtual void setAsEntityRef(const EntityRef& nValue);
public:
    virtual void add(PropValue* pValue) {}
    virtual int getCount() const { return 0; }
    virtual PropValue* getItems(int nIndex) { return nullptr; }
    virtual void setItems(int nIndex, PropValue* pValue) {}
    virtual void clear() {}
};

class GFCENGINE_API LeafPropValue : public PropValue
{
public:
    LeafPropValue() : m_bIsNull(true) {}
    virtual bool isNull() const { return m_bIsNull; }
protected:
    void setIsNull(bool bIsNull) { m_bIsNull = bIsNull; }
private:
    bool m_bIsNull;
};

class GFCENGINE_API CompositePropValue : public PropValue
{
public:
    CompositePropValue();
    virtual ~CompositePropValue();
public:
    virtual bool isNull() const { return getCount() == 0; }
    virtual void add(PropValue* pValue);
    virtual int getCount() const { return (int)m_oList.size(); }
    virtual PropValue* getItems(int nIndex) { return m_oList[nIndex]; }
    virtual void setItems(int nIndex, PropValue* pValue);
    virtual void clear();
private:
    std::vector<PropValue*> m_oList;
};

class GFCENGINE_API BooleanValue : public LeafPropValue
{
public:
    BooleanValue() : m_bValue(false) { }
    BooleanValue(bool bValue) : m_bValue(bValue) { setIsNull(false); }
public:
    //virtual std::string asString() const;
    virtual int asInteger() const;
    virtual double asDouble() const;
    virtual bool asBoolean() const;

    //virtual void setAsString(const std::string& sValue);
    virtual void setAsInteger(const int& nValue);
    virtual void setAsBoolean(const bool& bValue);
private:
    bool m_bValue;
};

class GFCENGINE_API IntegerValue : public LeafPropValue
{
public:
    IntegerValue() : m_nValue(0){ }
    IntegerValue(int nValue) : m_nValue(nValue) { setIsNull(false); }
public:
    //virtual std::string asString() const;
    virtual int asInteger() const;
    virtual double asDouble() const;
    virtual bool asBoolean() const;

    //virtual void setAsString(const std::string& sValue);
    virtual void setAsInteger(const int& nValue);
    virtual void setAsBoolean(const bool& bValue);
private:
    int m_nValue;
};

class GFCENGINE_API DoubleValue : public LeafPropValue
{
public:
    DoubleValue() : m_dValue(0.0) { }
    DoubleValue(double dValue) : m_dValue(dValue) { setIsNull(false); }
public:
    //virtual std::string asString() const;
    virtual double asDouble() const;

    //virtual void setAsString(const std::string& sValue);
    virtual void setAsInteger(const int& nValue);
    virtual void setAsDouble(const double& dValue);
    virtual void setAsBoolean(const bool& bValue);
private:
    double m_dValue;
};

class GFCENGINE_API StringValue : public LeafPropValue
{
public:
    StringValue() { }
    StringValue(const std::string& sValue): m_sValue(sValue) { setIsNull(false); }
public:
    virtual std::string asString() const;

    virtual void setAsString(const std::string& sValue);
    virtual void setAsInteger(const int& nValue);
    virtual void setAsDouble(const double& dValue);
    virtual void setAsBoolean(const bool& bValue);
private:
    std::string m_sValue;
};

class GFCENGINE_API EntityRefValue : public LeafPropValue
{
public:
    EntityRefValue() : m_nValue(-1) { }
    EntityRefValue(EntityRef nValue) : m_nValue(nValue) { setIsNull(false); }
public:
    virtual EntityRef asEntityRef() const;

    virtual void setAsEntityRef(const EntityRef& nValue);
private:
    EntityRef m_nValue;
};

GFCENGINE_NAMESPACE_END

#endif // !ATTRIBUTEVALUE_H
#ifndef ATTRIBUTEVALUE_H
#define ATTRIBUTEVALUE_H

#include <string>
#include <vector>
#include <memory>
#include "GfcSchema\SchemaMacro.h"

GFC_NAMESPACE_BEGIN

class CAttributeValue;

typedef std::shared_ptr<CAttributeValue> CAttributeValuePtr;

class CAttributeValue
{
public:
    CAttributeValue();
    virtual ~CAttributeValue();
public:
    virtual std::wstring asString() = 0;
    virtual void setAsString(const std::wstring& sValue) {}
    virtual void add(CAttributeValuePtr pValue) {}
    virtual int getCount() { return 0; }
    virtual CAttributeValuePtr getItems(int nIndex) { return nullptr; }
    virtual void setItems(int nIndex, CAttributeValuePtr pValue) {}
};

class CLeafAttributeValue: public CAttributeValue
{
public:
    CLeafAttributeValue();
    CLeafAttributeValue(const std::wstring& sValue);
    virtual ~CLeafAttributeValue();
public:
    virtual std::wstring asString();
    virtual void setAsString(const std::wstring& sValue);
private:
    std::wstring m_sValue;
};

class CCompositeAttributeValue : public CAttributeValue
{
public:
    CCompositeAttributeValue();
    virtual ~CCompositeAttributeValue();
public:
    virtual std::wstring asString();
    virtual void add(CAttributeValuePtr pValue);
    virtual int getCount() { return (int)m_oList.size(); }
    virtual CAttributeValuePtr getItems(int nIndex) { return m_oList[nIndex]; }
    virtual void setItems(int nIndex, CAttributeValuePtr pValue);
private:
    void clear();
    std::vector<CAttributeValuePtr> m_oList;
};

GFC_NAMESPACE_END

#endif // !ATTRIBUTEVALUE_H
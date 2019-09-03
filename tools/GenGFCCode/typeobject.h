#ifndef TYPEOBJECT_H
#define TYPEOBJECT_H

#include <string>

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
private:
    std::wstring m_sName;
};

#endif // TYPEOBJECT_H

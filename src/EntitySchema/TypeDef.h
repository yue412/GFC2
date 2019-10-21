#ifndef TYPEDEF_H
#define TYPEDEF_H

#include "TypeObject.h"

GFC_NAMESPACE_BEGIN

class CTypeDef : public CTypeObject
{
public:
    CTypeDef();
    CTypeDef(const std::wstring& sName);
    CTypeObject* getRefType() {return m_pRefType;}
    void SetRefType(CTypeObject* pType) {m_pRefType = pType;}
    virtual CTypeObjectEnum getType() const {return TOE_TYPE;}
    virtual bool getIsValueType();
    virtual CTypeObject* getBaseType();
private:
    CTypeObject* m_pRefType;
};

GFC_NAMESPACE_END

#endif // TYPEDEF_H

#ifndef TYPE_H
#define TYPE_H

#include "typeobject.h"

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

#endif // TYPE_H

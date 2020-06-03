#ifndef TYPEDEFINE_H
#define TYPEDEFINE_H

#include "GfcSchema\TypeObject.h"

GFC_NAMESPACE_BEGIN

class GFCSCHEMA_API CTypeDef : public CTypeObject
{
public:
    CTypeDef();
    CTypeDef(const std::wstring& sName);
    CTypeObject* getRefType() {return m_pRefType;}
    void SetRefType(CTypeObject* pType) {m_pRefType = pType;}
    virtual CTypeObjectEnum getType() const {return TOE_TYPE;}
    virtual bool getIsValueType();
    virtual CTypeObject* getBaseType();
    virtual CDataTypeEnum getDataType() const;
private:
    CTypeObject* m_pRefType;
};

GFC_NAMESPACE_END

#endif // TYPEDEFINE_H

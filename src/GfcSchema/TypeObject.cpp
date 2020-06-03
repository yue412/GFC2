#include "GfcSchema\TypeObject.h"

GFC_NAMESPACE_BEGIN

bool lessTypeObject(CTypeObject* type1, CTypeObject* type2)
{
    if (type1->getType() == type2->getType())
    {
        return type1->getName() < type2->getName();
    }
    else
    {
        return type1->getType() < type2->getType();
    }
}

CTypeObject::CTypeObject()
{
}

CTypeObject::CTypeObject(const std::wstring &sName): m_sName(sName)
{

}

bool CTypeObject::getIsValueType()
{
    return false;
}

CTypeObject *CTypeObject::getBaseType()
{
    return this;
}

CDataTypeEnum CTypeObject::getDataType() const 
{
    return EDT_UNKONWN;
}

GFC_NAMESPACE_END
#include "typeobject.h"

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

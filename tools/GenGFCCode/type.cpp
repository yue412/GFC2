#include "type.h"

CTypeDef::CTypeDef(): m_pRefType(NULL)
{
}

CTypeDef::CTypeDef(const std::wstring &sName): CTypeObject(sName), m_pRefType(NULL)
{

}

bool CTypeDef::getIsValueType()
{
    return m_pRefType->getIsValueType();
}

CTypeObject *CTypeDef::getBaseType()
{
    if (m_pRefType->getType() == TOE_TYPE)
        return m_pRefType->getBaseType();
    else
        return m_pRefType;
}

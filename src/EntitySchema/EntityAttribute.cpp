#include "EntityAttribute.h"
#include "TypeObject.h"
#include "EntityClass.h"
#include "TypeDef.h"

GFC_NAMESPACE_BEGIN

CAttribute::CAttribute(): m_pTypeObject(NULL), m_bOptional(false), m_bRepeat(false)/*, m_bRefFlag(true)*/
{
}

void CAttribute::SetType(CTypeObject *pType)
{
    m_pTypeObject = pType;
//    if (m_pTypeObject && m_pTypeObject->getIsValueType())
//        m_bRefFlag = false;
}

std::wstring CAttribute::getTypeName()
{
    std::wstring sType = this->getRepeatFlag() ? L"LIST [0:?] OF " + this->getType()->getName() : this->getType()->getName();
    return sType;
}

//bool CAttribute::getRefFlag()
//{
//    if (m_pTypeObject && m_pTypeObject->getBaseType()->getType() == TOE_CLASS)
//        return m_bRefFlag;
//    else
//        return true;
//}

//void CAttribute::setRefFlag(bool bRefFlag)
//{
//    if (m_pTypeObject && m_pTypeObject->getBaseType()->getType() == TOE_CLASS)
//        m_bRefFlag = bRefFlag;
//}

GFC_NAMESPACE_END
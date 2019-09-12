#include "attribute.h"
#include "typeobject.h"
#include "class.h"
#include "type.h"
#include "common.h"

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
    std::wstring sType = this->getRepeatFlag() ? L"LIST [0:?] OF %s" : L"%s";
    return FormatWstring(sType.c_str(),
        this->getType()->getName().c_str()
    );
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

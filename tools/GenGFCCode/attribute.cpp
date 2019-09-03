#include "attribute.h"
#include "typeobject.h"
#include "class.h"
#include "type.h"

CAttribute::CAttribute(): m_pTypeObject(NULL), m_bOptional(false), m_bRepeat(false)/*, m_bRefFlag(true)*/
{
}

void CAttribute::SetType(CTypeObject *pType)
{
    m_pTypeObject = pType;
//    if (m_pTypeObject && m_pTypeObject->getIsValueType())
//        m_bRefFlag = false;
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

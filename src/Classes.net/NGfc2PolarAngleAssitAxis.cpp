#include "StdAfx.h"
#include "NGfc2PolarAngleAssitAxis.h"
NGfc2PolarAngleAssitAxis::NGfc2PolarAngleAssitAxis()
{
    m_pEntity = new Gfc2PolarAngleAssitAxis;
    m_bOwner = true;
}

NGfc2PolarAngleAssitAxis::NGfc2PolarAngleAssitAxis(void* pEntity, bool bOwner):
    NGfc2AssitAxis(pEntity, bOwner)
{
}

void NGfc2PolarAngleAssitAxis::setRefAxisNo(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2PolarAngleAssitAxis*)m_pEntity)->setRefAxisNo(nValue);
}

glodon::objectbuf::EntityRef NGfc2PolarAngleAssitAxis::getRefAxisNo()
{
    return ((Gfc2PolarAngleAssitAxis*)m_pEntity)->getRefAxisNo();
}

bool NGfc2PolarAngleAssitAxis::hasRefAxisNo()
{
    return ((Gfc2PolarAngleAssitAxis*)m_pEntity)->hasRefAxisNo();
}

NGfc2Label^ NGfc2PolarAngleAssitAxis::getRefAxisNoPtr()
{
    return gcnew NGfc2Label(((Gfc2PolarAngleAssitAxis*)m_pEntity)->getRefAxisNoPtr(), false);
}

void NGfc2PolarAngleAssitAxis::setAngle(NGfc2Double dValue)
{
    ((Gfc2PolarAngleAssitAxis*)m_pEntity)->setAngle(dValue);
}

NGfc2Double NGfc2PolarAngleAssitAxis::getAngle()
{
    return ((Gfc2PolarAngleAssitAxis*)m_pEntity)->getAngle();
}

bool NGfc2PolarAngleAssitAxis::hasAngle()
{
    return ((Gfc2PolarAngleAssitAxis*)m_pEntity)->hasAngle();
}

void NGfc2PolarAngleAssitAxis::setRefAxisIndex(NGfc2Integer nValue)
{
    ((Gfc2PolarAngleAssitAxis*)m_pEntity)->setRefAxisIndex(nValue);
}

NGfc2Integer NGfc2PolarAngleAssitAxis::getRefAxisIndex()
{
    return ((Gfc2PolarAngleAssitAxis*)m_pEntity)->getRefAxisIndex();
}

bool NGfc2PolarAngleAssitAxis::hasRefAxisIndex()
{
    return ((Gfc2PolarAngleAssitAxis*)m_pEntity)->hasRefAxisIndex();
}


#include "StdAfx.h"
#include "NGfc2AxisAngleAssitAxis.h"
NGfc2AxisAngleAssitAxis::NGfc2AxisAngleAssitAxis()
{
    m_pEntity = new Gfc2AxisAngleAssitAxis;
    m_bOwner = true;
}

NGfc2AxisAngleAssitAxis::NGfc2AxisAngleAssitAxis(void* pEntity, bool bOwner):
    NGfc2AssitAxis(pEntity, bOwner)
{
}

void NGfc2AxisAngleAssitAxis::setRefAxisNo(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2AxisAngleAssitAxis*)m_pEntity)->setRefAxisNo(nValue);
}

glodon::objectbuf::EntityRef NGfc2AxisAngleAssitAxis::getRefAxisNo()
{
    return ((Gfc2AxisAngleAssitAxis*)m_pEntity)->getRefAxisNo();
}

bool NGfc2AxisAngleAssitAxis::hasRefAxisNo()
{
    return ((Gfc2AxisAngleAssitAxis*)m_pEntity)->hasRefAxisNo();
}

NGfc2Label^ NGfc2AxisAngleAssitAxis::getRefAxisNoPtr()
{
    return gcnew NGfc2Label(((Gfc2AxisAngleAssitAxis*)m_pEntity)->getRefAxisNoPtr(), false);
}

void NGfc2AxisAngleAssitAxis::setRefPoint(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2AxisAngleAssitAxis*)m_pEntity)->setRefPoint(nValue);
}

glodon::objectbuf::EntityRef NGfc2AxisAngleAssitAxis::getRefPoint()
{
    return ((Gfc2AxisAngleAssitAxis*)m_pEntity)->getRefPoint();
}

bool NGfc2AxisAngleAssitAxis::hasRefPoint()
{
    return ((Gfc2AxisAngleAssitAxis*)m_pEntity)->hasRefPoint();
}

NGfc2Vector2d^ NGfc2AxisAngleAssitAxis::getRefPointPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2AxisAngleAssitAxis*)m_pEntity)->getRefPointPtr(), false);
}

void NGfc2AxisAngleAssitAxis::setAngle(NGfc2Double dValue)
{
    ((Gfc2AxisAngleAssitAxis*)m_pEntity)->setAngle(dValue);
}

NGfc2Double NGfc2AxisAngleAssitAxis::getAngle()
{
    return ((Gfc2AxisAngleAssitAxis*)m_pEntity)->getAngle();
}

bool NGfc2AxisAngleAssitAxis::hasAngle()
{
    return ((Gfc2AxisAngleAssitAxis*)m_pEntity)->hasAngle();
}

void NGfc2AxisAngleAssitAxis::setRefAxisIndex(NGfc2Integer nValue)
{
    ((Gfc2AxisAngleAssitAxis*)m_pEntity)->setRefAxisIndex(nValue);
}

NGfc2Integer NGfc2AxisAngleAssitAxis::getRefAxisIndex()
{
    return ((Gfc2AxisAngleAssitAxis*)m_pEntity)->getRefAxisIndex();
}

bool NGfc2AxisAngleAssitAxis::hasRefAxisIndex()
{
    return ((Gfc2AxisAngleAssitAxis*)m_pEntity)->hasRefAxisIndex();
}

void NGfc2AxisAngleAssitAxis::setRefAxisType(NGfc2AxisType nValue)
{
    ((Gfc2AxisAngleAssitAxis*)m_pEntity)->setRefAxisType((Gfc2AxisType)nValue);
}

NGfc2AxisType NGfc2AxisAngleAssitAxis::getRefAxisType()
{
    return (NGfc2AxisType)((Gfc2AxisAngleAssitAxis*)m_pEntity)->getRefAxisType();
}

bool NGfc2AxisAngleAssitAxis::hasRefAxisType()
{
    return ((Gfc2AxisAngleAssitAxis*)m_pEntity)->hasRefAxisType();
}


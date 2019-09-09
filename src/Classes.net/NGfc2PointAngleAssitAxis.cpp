#include "StdAfx.h"
#include "NGfc2PointAngleAssitAxis.h"
NGfc2PointAngleAssitAxis::NGfc2PointAngleAssitAxis()
{
    m_pEntity = new Gfc2PointAngleAssitAxis;
    m_bOwner = true;
}

NGfc2PointAngleAssitAxis::NGfc2PointAngleAssitAxis(void* pEntity, bool bOwner):
    NGfc2AssitAxis(pEntity, bOwner)
{
}

void NGfc2PointAngleAssitAxis::setRefPoint(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2PointAngleAssitAxis*)m_pEntity)->setRefPoint(nValue);
}

glodon::objectbuf::EntityRef NGfc2PointAngleAssitAxis::getRefPoint()
{
    return ((Gfc2PointAngleAssitAxis*)m_pEntity)->getRefPoint();
}

bool NGfc2PointAngleAssitAxis::hasRefPoint()
{
    return ((Gfc2PointAngleAssitAxis*)m_pEntity)->hasRefPoint();
}

NGfc2Vector2d^ NGfc2PointAngleAssitAxis::getRefPointPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2PointAngleAssitAxis*)m_pEntity)->getRefPointPtr(), false);
}

void NGfc2PointAngleAssitAxis::setAngle(NGfc2Double dValue)
{
    ((Gfc2PointAngleAssitAxis*)m_pEntity)->setAngle(dValue);
}

NGfc2Double NGfc2PointAngleAssitAxis::getAngle()
{
    return ((Gfc2PointAngleAssitAxis*)m_pEntity)->getAngle();
}

bool NGfc2PointAngleAssitAxis::hasAngle()
{
    return ((Gfc2PointAngleAssitAxis*)m_pEntity)->hasAngle();
}


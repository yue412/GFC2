#include "StdAfx.h"
#include "NGfc2CenterStartEndArcAssitAxis.h"
NGfc2CenterStartEndArcAssitAxis::NGfc2CenterStartEndArcAssitAxis()
{
    m_pEntity = new Gfc2CenterStartEndArcAssitAxis;
    m_bOwner = true;
}

NGfc2CenterStartEndArcAssitAxis::NGfc2CenterStartEndArcAssitAxis(void* pEntity, bool bOwner):
    NGfc2AssitAxis(pEntity, bOwner)
{
}

void NGfc2CenterStartEndArcAssitAxis::setCenter(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2CenterStartEndArcAssitAxis*)m_pEntity)->setCenter(nValue);
}

glodon::objectbuf::EntityRef NGfc2CenterStartEndArcAssitAxis::getCenter()
{
    return ((Gfc2CenterStartEndArcAssitAxis*)m_pEntity)->getCenter();
}

bool NGfc2CenterStartEndArcAssitAxis::hasCenter()
{
    return ((Gfc2CenterStartEndArcAssitAxis*)m_pEntity)->hasCenter();
}

NGfc2Vector2d^ NGfc2CenterStartEndArcAssitAxis::getCenterPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2CenterStartEndArcAssitAxis*)m_pEntity)->getCenterPtr(), false);
}

void NGfc2CenterStartEndArcAssitAxis::setStartPoint(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2CenterStartEndArcAssitAxis*)m_pEntity)->setStartPoint(nValue);
}

glodon::objectbuf::EntityRef NGfc2CenterStartEndArcAssitAxis::getStartPoint()
{
    return ((Gfc2CenterStartEndArcAssitAxis*)m_pEntity)->getStartPoint();
}

bool NGfc2CenterStartEndArcAssitAxis::hasStartPoint()
{
    return ((Gfc2CenterStartEndArcAssitAxis*)m_pEntity)->hasStartPoint();
}

NGfc2Vector2d^ NGfc2CenterStartEndArcAssitAxis::getStartPointPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2CenterStartEndArcAssitAxis*)m_pEntity)->getStartPointPtr(), false);
}

void NGfc2CenterStartEndArcAssitAxis::setEndPoint(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2CenterStartEndArcAssitAxis*)m_pEntity)->setEndPoint(nValue);
}

glodon::objectbuf::EntityRef NGfc2CenterStartEndArcAssitAxis::getEndPoint()
{
    return ((Gfc2CenterStartEndArcAssitAxis*)m_pEntity)->getEndPoint();
}

bool NGfc2CenterStartEndArcAssitAxis::hasEndPoint()
{
    return ((Gfc2CenterStartEndArcAssitAxis*)m_pEntity)->hasEndPoint();
}

NGfc2Vector2d^ NGfc2CenterStartEndArcAssitAxis::getEndPointPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2CenterStartEndArcAssitAxis*)m_pEntity)->getEndPointPtr(), false);
}


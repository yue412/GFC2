#include "StdAfx.h"
#include "NGfc2CircleAssitAxis.h"
NGfc2CircleAssitAxis::NGfc2CircleAssitAxis()
{
    m_pEntity = new Gfc2CircleAssitAxis;
    m_bOwner = true;
}

NGfc2CircleAssitAxis::NGfc2CircleAssitAxis(void* pEntity, bool bOwner):
    NGfc2AssitAxis(pEntity, bOwner)
{
}

void NGfc2CircleAssitAxis::setCenter(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2CircleAssitAxis*)m_pEntity)->setCenter(nValue);
}

glodon::objectbuf::EntityRef NGfc2CircleAssitAxis::getCenter()
{
    return ((Gfc2CircleAssitAxis*)m_pEntity)->getCenter();
}

bool NGfc2CircleAssitAxis::hasCenter()
{
    return ((Gfc2CircleAssitAxis*)m_pEntity)->hasCenter();
}

NGfc2Vector2d^ NGfc2CircleAssitAxis::getCenterPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2CircleAssitAxis*)m_pEntity)->getCenterPtr(), false);
}

void NGfc2CircleAssitAxis::setRadius(NGfc2Double dValue)
{
    ((Gfc2CircleAssitAxis*)m_pEntity)->setRadius(dValue);
}

NGfc2Double NGfc2CircleAssitAxis::getRadius()
{
    return ((Gfc2CircleAssitAxis*)m_pEntity)->getRadius();
}

bool NGfc2CircleAssitAxis::hasRadius()
{
    return ((Gfc2CircleAssitAxis*)m_pEntity)->hasRadius();
}


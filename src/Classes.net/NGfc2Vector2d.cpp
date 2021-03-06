#include "StdAfx.h"
#include "NGfc2Vector2d.h"
NGfc2Vector2d::NGfc2Vector2d()
{
    m_pEntity = new Gfc2Vector2d;
    m_bOwner = true;
}

NGfc2Vector2d::NGfc2Vector2d(void* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

void NGfc2Vector2d::setX(NGfc2Double dValue)
{
    ((Gfc2Vector2d*)m_pEntity)->setX(dValue);
}

NGfc2Double NGfc2Vector2d::getX()
{
    return ((Gfc2Vector2d*)m_pEntity)->getX();
}

bool NGfc2Vector2d::hasX()
{
    return ((Gfc2Vector2d*)m_pEntity)->hasX();
}

void NGfc2Vector2d::setY(NGfc2Double dValue)
{
    ((Gfc2Vector2d*)m_pEntity)->setY(dValue);
}

NGfc2Double NGfc2Vector2d::getY()
{
    return ((Gfc2Vector2d*)m_pEntity)->getY();
}

bool NGfc2Vector2d::hasY()
{
    return ((Gfc2Vector2d*)m_pEntity)->hasY();
}


#include "StdAfx.h"
#include "NGfc2Shape2d.h"
NGfc2Shape2d::NGfc2Shape2d()
{
    m_pEntity = new Gfc2Shape2d;
    m_bOwner = true;
}

NGfc2Shape2d::NGfc2Shape2d(void* pEntity, bool bOwner):
    NGfc2ParametricShape(pEntity, bOwner)
{
}

void NGfc2Shape2d::setElev(NGfc2Double dValue)
{
    ((Gfc2Shape2d*)m_pEntity)->setElev(dValue);
}

NGfc2Double NGfc2Shape2d::getElev()
{
    return ((Gfc2Shape2d*)m_pEntity)->getElev();
}

bool NGfc2Shape2d::hasElev()
{
    return ((Gfc2Shape2d*)m_pEntity)->hasElev();
}


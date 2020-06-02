#include "StdAfx.h"
#include "NGfc2Line2d.h"
NGfc2Line2d::NGfc2Line2d()
{
    m_pEntity = new Gfc2Line2d;
    m_bOwner = true;
}

NGfc2Line2d::NGfc2Line2d(void* pEntity, bool bOwner):
    NGfc2Curve2d(pEntity, bOwner)
{
}

void NGfc2Line2d::setStartPt(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Line2d*)m_pEntity)->setStartPt(nValue);
}

gfc2::engine::EntityRef NGfc2Line2d::getStartPt()
{
    return ((Gfc2Line2d*)m_pEntity)->getStartPt();
}

bool NGfc2Line2d::hasStartPt()
{
    return ((Gfc2Line2d*)m_pEntity)->hasStartPt();
}

NGfc2Vector2d^ NGfc2Line2d::getStartPtPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2Line2d*)m_pEntity)->getStartPtPtr(), false);
}

void NGfc2Line2d::setEndPt(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Line2d*)m_pEntity)->setEndPt(nValue);
}

gfc2::engine::EntityRef NGfc2Line2d::getEndPt()
{
    return ((Gfc2Line2d*)m_pEntity)->getEndPt();
}

bool NGfc2Line2d::hasEndPt()
{
    return ((Gfc2Line2d*)m_pEntity)->hasEndPt();
}

NGfc2Vector2d^ NGfc2Line2d::getEndPtPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2Line2d*)m_pEntity)->getEndPtPtr(), false);
}


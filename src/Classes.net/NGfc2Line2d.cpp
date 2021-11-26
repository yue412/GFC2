#include "NGfc2Line2d.h"

using namespace gfc::classes::x3;

NGfc2Line2d::NGfc2Line2d()
{
    m_pEntity = new Gfc2Line2d;
    m_bOwner = true;
}

NGfc2Line2d::NGfc2Line2d(void* pEntity, bool bOwner):
    NGfc2Curve2d(pEntity, bOwner)
{
}

void NGfc2Line2d::setStartPt(gfc::engine::EntityRef nValue)
{
    ((Gfc2Line2d*)m_pEntity)->setStartPt(nValue);
}

gfc::engine::EntityRef NGfc2Line2d::getStartPt()
{
    return ((Gfc2Line2d*)m_pEntity)->getStartPt();
}

bool NGfc2Line2d::hasStartPt()
{
    return ((Gfc2Line2d*)m_pEntity)->hasStartPt();
}

void NGfc2Line2d::setEndPt(gfc::engine::EntityRef nValue)
{
    ((Gfc2Line2d*)m_pEntity)->setEndPt(nValue);
}

gfc::engine::EntityRef NGfc2Line2d::getEndPt()
{
    return ((Gfc2Line2d*)m_pEntity)->getEndPt();
}

bool NGfc2Line2d::hasEndPt()
{
    return ((Gfc2Line2d*)m_pEntity)->hasEndPt();
}


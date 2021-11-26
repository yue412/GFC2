#include "NGfc2Line3d.h"

using namespace gfc::classes::x3;

NGfc2Line3d::NGfc2Line3d()
{
    m_pEntity = new Gfc2Line3d;
    m_bOwner = true;
}

NGfc2Line3d::NGfc2Line3d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Curve3d(pEntity, bOwner)
{
}

void NGfc2Line3d::setStartPt(gfc::engine::EntityRef nValue)
{
    ((Gfc2Line3d*)m_pEntity)->setStartPt(nValue);
}

gfc::engine::EntityRef NGfc2Line3d::getStartPt()
{
    return ((Gfc2Line3d*)m_pEntity)->getStartPt();
}

bool NGfc2Line3d::hasStartPt()
{
    return ((Gfc2Line3d*)m_pEntity)->hasStartPt();
}

void NGfc2Line3d::setEndPt(gfc::engine::EntityRef nValue)
{
    ((Gfc2Line3d*)m_pEntity)->setEndPt(nValue);
}

gfc::engine::EntityRef NGfc2Line3d::getEndPt()
{
    return ((Gfc2Line3d*)m_pEntity)->getEndPt();
}

bool NGfc2Line3d::hasEndPt()
{
    return ((Gfc2Line3d*)m_pEntity)->hasEndPt();
}


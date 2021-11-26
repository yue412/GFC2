#include "NGfc2PlaneCurve3d.h"

using namespace gfc::classes::x3;

NGfc2PlaneCurve3d::NGfc2PlaneCurve3d()
{
    m_pEntity = new Gfc2PlaneCurve3d;
    m_bOwner = true;
}

NGfc2PlaneCurve3d::NGfc2PlaneCurve3d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Curve3d(pEntity, bOwner)
{
}

void NGfc2PlaneCurve3d::setPlaneCurve(gfc::engine::EntityRef nValue)
{
    ((Gfc2PlaneCurve3d*)m_pEntity)->setPlaneCurve(nValue);
}

gfc::engine::EntityRef NGfc2PlaneCurve3d::getPlaneCurve()
{
    return ((Gfc2PlaneCurve3d*)m_pEntity)->getPlaneCurve();
}

bool NGfc2PlaneCurve3d::hasPlaneCurve()
{
    return ((Gfc2PlaneCurve3d*)m_pEntity)->hasPlaneCurve();
}

void NGfc2PlaneCurve3d::setPlane(gfc::engine::EntityRef nValue)
{
    ((Gfc2PlaneCurve3d*)m_pEntity)->setPlane(nValue);
}

gfc::engine::EntityRef NGfc2PlaneCurve3d::getPlane()
{
    return ((Gfc2PlaneCurve3d*)m_pEntity)->getPlane();
}

bool NGfc2PlaneCurve3d::hasPlane()
{
    return ((Gfc2PlaneCurve3d*)m_pEntity)->hasPlane();
}


#include "NGfcPlaneCurve3d.h"

using namespace gfc::classes::x3;

NGfcPlaneCurve3d::NGfcPlaneCurve3d()
{
    m_pEntity = new GfcPlaneCurve3d;
    m_bOwner = true;
}

NGfcPlaneCurve3d::NGfcPlaneCurve3d(bool bNoCreate):
    NGfcCurve3d(bNoCreate)
{
}

void NGfcPlaneCurve3d::setPlaneCurve(gfc::engine::EntityRef nValue)
{
    ((GfcPlaneCurve3d*)m_pEntity)->setPlaneCurve(nValue);
}

gfc::engine::EntityRef NGfcPlaneCurve3d::getPlaneCurve()
{
    return ((GfcPlaneCurve3d*)m_pEntity)->getPlaneCurve();
}

bool NGfcPlaneCurve3d::hasPlaneCurve()
{
    return ((GfcPlaneCurve3d*)m_pEntity)->hasPlaneCurve();
}

void NGfcPlaneCurve3d::setPlane(gfc::engine::EntityRef nValue)
{
    ((GfcPlaneCurve3d*)m_pEntity)->setPlane(nValue);
}

gfc::engine::EntityRef NGfcPlaneCurve3d::getPlane()
{
    return ((GfcPlaneCurve3d*)m_pEntity)->getPlane();
}

bool NGfcPlaneCurve3d::hasPlane()
{
    return ((GfcPlaneCurve3d*)m_pEntity)->hasPlane();
}


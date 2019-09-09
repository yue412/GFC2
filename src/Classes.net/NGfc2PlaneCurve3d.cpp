#include "StdAfx.h"
#include "NGfc2PlaneCurve3d.h"
NGfc2PlaneCurve3d::NGfc2PlaneCurve3d()
{
    m_pEntity = new Gfc2PlaneCurve3d;
    m_bOwner = true;
}

NGfc2PlaneCurve3d::NGfc2PlaneCurve3d(void* pEntity, bool bOwner):
    NGfc2Curve3d(pEntity, bOwner)
{
}

void NGfc2PlaneCurve3d::setPlaneCurve(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2PlaneCurve3d*)m_pEntity)->setPlaneCurve(nValue);
}

glodon::objectbuf::EntityRef NGfc2PlaneCurve3d::getPlaneCurve()
{
    return ((Gfc2PlaneCurve3d*)m_pEntity)->getPlaneCurve();
}

bool NGfc2PlaneCurve3d::hasPlaneCurve()
{
    return ((Gfc2PlaneCurve3d*)m_pEntity)->hasPlaneCurve();
}

NGfc2Curve2d^ NGfc2PlaneCurve3d::getPlaneCurvePtr()
{
    return gcnew NGfc2Curve2d(((Gfc2PlaneCurve3d*)m_pEntity)->getPlaneCurvePtr(), false);
}

void NGfc2PlaneCurve3d::setPlane(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2PlaneCurve3d*)m_pEntity)->setPlane(nValue);
}

glodon::objectbuf::EntityRef NGfc2PlaneCurve3d::getPlane()
{
    return ((Gfc2PlaneCurve3d*)m_pEntity)->getPlane();
}

bool NGfc2PlaneCurve3d::hasPlane()
{
    return ((Gfc2PlaneCurve3d*)m_pEntity)->hasPlane();
}

NGfc2PlaneInfo^ NGfc2PlaneCurve3d::getPlanePtr()
{
    return gcnew NGfc2PlaneInfo(((Gfc2PlaneCurve3d*)m_pEntity)->getPlanePtr(), false);
}


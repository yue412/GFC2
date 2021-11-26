#include "NGfc2SweepCurve3d.h"

using namespace gfc::classes::x3;

NGfc2SweepCurve3d::NGfc2SweepCurve3d()
{
    m_pEntity = new Gfc2SweepCurve3d;
    m_bOwner = true;
}

NGfc2SweepCurve3d::NGfc2SweepCurve3d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Curve3d(pEntity, bOwner)
{
}

void NGfc2SweepCurve3d::setSpine3d(gfc::engine::EntityRef nValue)
{
    ((Gfc2SweepCurve3d*)m_pEntity)->setSpine3d(nValue);
}

gfc::engine::EntityRef NGfc2SweepCurve3d::getSpine3d()
{
    return ((Gfc2SweepCurve3d*)m_pEntity)->getSpine3d();
}

bool NGfc2SweepCurve3d::hasSpine3d()
{
    return ((Gfc2SweepCurve3d*)m_pEntity)->hasSpine3d();
}

void NGfc2SweepCurve3d::setReferenceVector(gfc::engine::EntityRef nValue)
{
    ((Gfc2SweepCurve3d*)m_pEntity)->setReferenceVector(nValue);
}

gfc::engine::EntityRef NGfc2SweepCurve3d::getReferenceVector()
{
    return ((Gfc2SweepCurve3d*)m_pEntity)->getReferenceVector();
}

bool NGfc2SweepCurve3d::hasReferenceVector()
{
    return ((Gfc2SweepCurve3d*)m_pEntity)->hasReferenceVector();
}

void NGfc2SweepCurve3d::setPoint(gfc::engine::EntityRef nValue)
{
    ((Gfc2SweepCurve3d*)m_pEntity)->setPoint(nValue);
}

gfc::engine::EntityRef NGfc2SweepCurve3d::getPoint()
{
    return ((Gfc2SweepCurve3d*)m_pEntity)->getPoint();
}

bool NGfc2SweepCurve3d::hasPoint()
{
    return ((Gfc2SweepCurve3d*)m_pEntity)->hasPoint();
}

void NGfc2SweepCurve3d::setSweepType(NGfc2SweepType nValue)
{
    ((Gfc2SweepCurve3d*)m_pEntity)->setSweepType((Gfc2SweepType)nValue);
}

NGfc2SweepType NGfc2SweepCurve3d::getSweepType()
{
    return (NGfc2SweepType)((Gfc2SweepCurve3d*)m_pEntity)->getSweepType();
}

bool NGfc2SweepCurve3d::hasSweepType()
{
    return ((Gfc2SweepCurve3d*)m_pEntity)->hasSweepType();
}


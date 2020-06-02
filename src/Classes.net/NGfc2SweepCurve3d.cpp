#include "StdAfx.h"
#include "NGfc2SweepCurve3d.h"
NGfc2SweepCurve3d::NGfc2SweepCurve3d()
{
    m_pEntity = new Gfc2SweepCurve3d;
    m_bOwner = true;
}

NGfc2SweepCurve3d::NGfc2SweepCurve3d(void* pEntity, bool bOwner):
    NGfc2Curve3d(pEntity, bOwner)
{
}

void NGfc2SweepCurve3d::setSpine3d(gfc2::engine::EntityRef nValue)
{
    ((Gfc2SweepCurve3d*)m_pEntity)->setSpine3d(nValue);
}

gfc2::engine::EntityRef NGfc2SweepCurve3d::getSpine3d()
{
    return ((Gfc2SweepCurve3d*)m_pEntity)->getSpine3d();
}

bool NGfc2SweepCurve3d::hasSpine3d()
{
    return ((Gfc2SweepCurve3d*)m_pEntity)->hasSpine3d();
}

NGfc2Curve3d^ NGfc2SweepCurve3d::getSpine3dPtr()
{
    return gcnew NGfc2Curve3d(((Gfc2SweepCurve3d*)m_pEntity)->getSpine3dPtr(), false);
}

void NGfc2SweepCurve3d::setReferenceVector(gfc2::engine::EntityRef nValue)
{
    ((Gfc2SweepCurve3d*)m_pEntity)->setReferenceVector(nValue);
}

gfc2::engine::EntityRef NGfc2SweepCurve3d::getReferenceVector()
{
    return ((Gfc2SweepCurve3d*)m_pEntity)->getReferenceVector();
}

bool NGfc2SweepCurve3d::hasReferenceVector()
{
    return ((Gfc2SweepCurve3d*)m_pEntity)->hasReferenceVector();
}

NGfc2Vector3d^ NGfc2SweepCurve3d::getReferenceVectorPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2SweepCurve3d*)m_pEntity)->getReferenceVectorPtr(), false);
}

void NGfc2SweepCurve3d::setPoint(gfc2::engine::EntityRef nValue)
{
    ((Gfc2SweepCurve3d*)m_pEntity)->setPoint(nValue);
}

gfc2::engine::EntityRef NGfc2SweepCurve3d::getPoint()
{
    return ((Gfc2SweepCurve3d*)m_pEntity)->getPoint();
}

bool NGfc2SweepCurve3d::hasPoint()
{
    return ((Gfc2SweepCurve3d*)m_pEntity)->hasPoint();
}

NGfc2Vector2d^ NGfc2SweepCurve3d::getPointPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2SweepCurve3d*)m_pEntity)->getPointPtr(), false);
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


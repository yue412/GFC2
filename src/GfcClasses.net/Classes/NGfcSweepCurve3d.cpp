#include "NGfcSweepCurve3d.h"

using namespace gfc::classes::x3;

NGfcSweepCurve3d::NGfcSweepCurve3d()
{
    m_pEntity = new GfcSweepCurve3d;
    m_bOwner = true;
}

NGfcSweepCurve3d::NGfcSweepCurve3d(bool bNoCreate):
    NGfcCurve3d(bNoCreate)
{
}

void NGfcSweepCurve3d::setSpine3d(gfc::engine::EntityRef nValue)
{
    ((GfcSweepCurve3d*)m_pEntity)->setSpine3d(nValue);
}

gfc::engine::EntityRef NGfcSweepCurve3d::getSpine3d()
{
    return ((GfcSweepCurve3d*)m_pEntity)->getSpine3d();
}

bool NGfcSweepCurve3d::hasSpine3d()
{
    return ((GfcSweepCurve3d*)m_pEntity)->hasSpine3d();
}

void NGfcSweepCurve3d::setReferenceVector(gfc::engine::EntityRef nValue)
{
    ((GfcSweepCurve3d*)m_pEntity)->setReferenceVector(nValue);
}

gfc::engine::EntityRef NGfcSweepCurve3d::getReferenceVector()
{
    return ((GfcSweepCurve3d*)m_pEntity)->getReferenceVector();
}

bool NGfcSweepCurve3d::hasReferenceVector()
{
    return ((GfcSweepCurve3d*)m_pEntity)->hasReferenceVector();
}

void NGfcSweepCurve3d::setPoint(gfc::engine::EntityRef nValue)
{
    ((GfcSweepCurve3d*)m_pEntity)->setPoint(nValue);
}

gfc::engine::EntityRef NGfcSweepCurve3d::getPoint()
{
    return ((GfcSweepCurve3d*)m_pEntity)->getPoint();
}

bool NGfcSweepCurve3d::hasPoint()
{
    return ((GfcSweepCurve3d*)m_pEntity)->hasPoint();
}

void NGfcSweepCurve3d::setSweepType(NGfcSweepType nValue)
{
    ((GfcSweepCurve3d*)m_pEntity)->setSweepType((GfcSweepType)nValue);
}

NGfcSweepType NGfcSweepCurve3d::getSweepType()
{
    return (NGfcSweepType)((GfcSweepCurve3d*)m_pEntity)->getSweepType();
}

bool NGfcSweepCurve3d::hasSweepType()
{
    return ((GfcSweepCurve3d*)m_pEntity)->hasSweepType();
}


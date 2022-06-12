#include "NGfcSweep.h"

using namespace gfc::classes::x3;

NGfcSweep::NGfcSweep()
{
    m_pEntity = new GfcSweep;
    m_bOwner = true;
}

NGfcSweep::NGfcSweep(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSurface(pEntity, bOwner)
{
}

void NGfcSweep::setProfile(gfc::engine::EntityRef nValue)
{
    ((GfcSweep*)m_pEntity)->setProfile(nValue);
}

gfc::engine::EntityRef NGfcSweep::getProfile()
{
    return ((GfcSweep*)m_pEntity)->getProfile();
}

bool NGfcSweep::hasProfile()
{
    return ((GfcSweep*)m_pEntity)->hasProfile();
}

void NGfcSweep::setSpine3d(gfc::engine::EntityRef nValue)
{
    ((GfcSweep*)m_pEntity)->setSpine3d(nValue);
}

gfc::engine::EntityRef NGfcSweep::getSpine3d()
{
    return ((GfcSweep*)m_pEntity)->getSpine3d();
}

bool NGfcSweep::hasSpine3d()
{
    return ((GfcSweep*)m_pEntity)->hasSpine3d();
}

void NGfcSweep::setReferenceVector(gfc::engine::EntityRef nValue)
{
    ((GfcSweep*)m_pEntity)->setReferenceVector(nValue);
}

gfc::engine::EntityRef NGfcSweep::getReferenceVector()
{
    return ((GfcSweep*)m_pEntity)->getReferenceVector();
}

bool NGfcSweep::hasReferenceVector()
{
    return ((GfcSweep*)m_pEntity)->hasReferenceVector();
}

void NGfcSweep::setSweepType(NGfcSweepType nValue)
{
    ((GfcSweep*)m_pEntity)->setSweepType((GfcSweepType)nValue);
}

NGfcSweepType NGfcSweep::getSweepType()
{
    return (NGfcSweepType)((GfcSweep*)m_pEntity)->getSweepType();
}

bool NGfcSweep::hasSweepType()
{
    return ((GfcSweep*)m_pEntity)->hasSweepType();
}


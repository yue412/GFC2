#include "NGfc2Sweep.h"

using namespace gfc::classes::x3;

NGfc2Sweep::NGfc2Sweep()
{
    m_pEntity = new Gfc2Sweep;
    m_bOwner = true;
}

NGfc2Sweep::NGfc2Sweep(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Surface(pEntity, bOwner)
{
}

void NGfc2Sweep::setProfile(gfc::engine::EntityRef nValue)
{
    ((Gfc2Sweep*)m_pEntity)->setProfile(nValue);
}

gfc::engine::EntityRef NGfc2Sweep::getProfile()
{
    return ((Gfc2Sweep*)m_pEntity)->getProfile();
}

bool NGfc2Sweep::hasProfile()
{
    return ((Gfc2Sweep*)m_pEntity)->hasProfile();
}

void NGfc2Sweep::setSpine3d(gfc::engine::EntityRef nValue)
{
    ((Gfc2Sweep*)m_pEntity)->setSpine3d(nValue);
}

gfc::engine::EntityRef NGfc2Sweep::getSpine3d()
{
    return ((Gfc2Sweep*)m_pEntity)->getSpine3d();
}

bool NGfc2Sweep::hasSpine3d()
{
    return ((Gfc2Sweep*)m_pEntity)->hasSpine3d();
}

void NGfc2Sweep::setReferenceVector(gfc::engine::EntityRef nValue)
{
    ((Gfc2Sweep*)m_pEntity)->setReferenceVector(nValue);
}

gfc::engine::EntityRef NGfc2Sweep::getReferenceVector()
{
    return ((Gfc2Sweep*)m_pEntity)->getReferenceVector();
}

bool NGfc2Sweep::hasReferenceVector()
{
    return ((Gfc2Sweep*)m_pEntity)->hasReferenceVector();
}

void NGfc2Sweep::setSweepType(NGfc2SweepType nValue)
{
    ((Gfc2Sweep*)m_pEntity)->setSweepType((Gfc2SweepType)nValue);
}

NGfc2SweepType NGfc2Sweep::getSweepType()
{
    return (NGfc2SweepType)((Gfc2Sweep*)m_pEntity)->getSweepType();
}

bool NGfc2Sweep::hasSweepType()
{
    return ((Gfc2Sweep*)m_pEntity)->hasSweepType();
}


#include "StdAfx.h"
#include "NGfc2Sweep.h"
NGfc2Sweep::NGfc2Sweep()
{
    m_pEntity = new Gfc2Sweep;
    m_bOwner = true;
}

NGfc2Sweep::NGfc2Sweep(void* pEntity, bool bOwner):
    NGfc2Surface(pEntity, bOwner)
{
}

void NGfc2Sweep::setProfile(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Sweep*)m_pEntity)->setProfile(nValue);
}

glodon::objectbuf::EntityRef NGfc2Sweep::getProfile()
{
    return ((Gfc2Sweep*)m_pEntity)->getProfile();
}

bool NGfc2Sweep::hasProfile()
{
    return ((Gfc2Sweep*)m_pEntity)->hasProfile();
}

NGfc2Curve2d^ NGfc2Sweep::getProfilePtr()
{
    return gcnew NGfc2Curve2d(((Gfc2Sweep*)m_pEntity)->getProfilePtr(), false);
}

void NGfc2Sweep::setSpine3d(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Sweep*)m_pEntity)->setSpine3d(nValue);
}

glodon::objectbuf::EntityRef NGfc2Sweep::getSpine3d()
{
    return ((Gfc2Sweep*)m_pEntity)->getSpine3d();
}

bool NGfc2Sweep::hasSpine3d()
{
    return ((Gfc2Sweep*)m_pEntity)->hasSpine3d();
}

NGfc2Curve3d^ NGfc2Sweep::getSpine3dPtr()
{
    return gcnew NGfc2Curve3d(((Gfc2Sweep*)m_pEntity)->getSpine3dPtr(), false);
}

void NGfc2Sweep::setReferenceVector(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Sweep*)m_pEntity)->setReferenceVector(nValue);
}

glodon::objectbuf::EntityRef NGfc2Sweep::getReferenceVector()
{
    return ((Gfc2Sweep*)m_pEntity)->getReferenceVector();
}

bool NGfc2Sweep::hasReferenceVector()
{
    return ((Gfc2Sweep*)m_pEntity)->hasReferenceVector();
}

NGfc2Vector3d^ NGfc2Sweep::getReferenceVectorPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2Sweep*)m_pEntity)->getReferenceVectorPtr(), false);
}


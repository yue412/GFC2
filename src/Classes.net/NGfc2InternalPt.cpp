#include "StdAfx.h"
#include "NGfc2InternalPt.h"
NGfc2InternalPt::NGfc2InternalPt()
{
    m_pEntity = new Gfc2InternalPt;
    m_bOwner = true;
}

NGfc2InternalPt::NGfc2InternalPt(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2InternalPt::setP(gfc2::engine::EntityRef nValue)
{
    ((Gfc2InternalPt*)m_pEntity)->setP(nValue);
}

gfc2::engine::EntityRef NGfc2InternalPt::getP()
{
    return ((Gfc2InternalPt*)m_pEntity)->getP();
}

bool NGfc2InternalPt::hasP()
{
    return ((Gfc2InternalPt*)m_pEntity)->hasP();
}

NGfc2Vector3d^ NGfc2InternalPt::getPPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2InternalPt*)m_pEntity)->getPPtr(), false);
}

void NGfc2InternalPt::setTVec(gfc2::engine::EntityRef nValue)
{
    ((Gfc2InternalPt*)m_pEntity)->setTVec(nValue);
}

gfc2::engine::EntityRef NGfc2InternalPt::getTVec()
{
    return ((Gfc2InternalPt*)m_pEntity)->getTVec();
}

bool NGfc2InternalPt::hasTVec()
{
    return ((Gfc2InternalPt*)m_pEntity)->hasTVec();
}

NGfc2Vector3d^ NGfc2InternalPt::getTVecPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2InternalPt*)m_pEntity)->getTVecPtr(), false);
}

void NGfc2InternalPt::setT(NGfc2Double dValue)
{
    ((Gfc2InternalPt*)m_pEntity)->setT(dValue);
}

NGfc2Double NGfc2InternalPt::getT()
{
    return ((Gfc2InternalPt*)m_pEntity)->getT();
}

bool NGfc2InternalPt::hasT()
{
    return ((Gfc2InternalPt*)m_pEntity)->hasT();
}

void NGfc2InternalPt::setUV(gfc2::engine::EntityRef nValue)
{
    ((Gfc2InternalPt*)m_pEntity)->setUV(nValue);
}

gfc2::engine::EntityRef NGfc2InternalPt::getUV()
{
    return ((Gfc2InternalPt*)m_pEntity)->getUV();
}

bool NGfc2InternalPt::hasUV()
{
    return ((Gfc2InternalPt*)m_pEntity)->hasUV();
}

NGfc2Vector2d^ NGfc2InternalPt::getUVPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2InternalPt*)m_pEntity)->getUVPtr(), false);
}

void NGfc2InternalPt::setST(gfc2::engine::EntityRef nValue)
{
    ((Gfc2InternalPt*)m_pEntity)->setST(nValue);
}

gfc2::engine::EntityRef NGfc2InternalPt::getST()
{
    return ((Gfc2InternalPt*)m_pEntity)->getST();
}

bool NGfc2InternalPt::hasST()
{
    return ((Gfc2InternalPt*)m_pEntity)->hasST();
}

NGfc2Vector2d^ NGfc2InternalPt::getSTPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2InternalPt*)m_pEntity)->getSTPtr(), false);
}

void NGfc2InternalPt::setUVDir(gfc2::engine::EntityRef nValue)
{
    ((Gfc2InternalPt*)m_pEntity)->setUVDir(nValue);
}

gfc2::engine::EntityRef NGfc2InternalPt::getUVDir()
{
    return ((Gfc2InternalPt*)m_pEntity)->getUVDir();
}

bool NGfc2InternalPt::hasUVDir()
{
    return ((Gfc2InternalPt*)m_pEntity)->hasUVDir();
}

NGfc2Vector2d^ NGfc2InternalPt::getUVDirPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2InternalPt*)m_pEntity)->getUVDirPtr(), false);
}

void NGfc2InternalPt::setSTDir(gfc2::engine::EntityRef nValue)
{
    ((Gfc2InternalPt*)m_pEntity)->setSTDir(nValue);
}

gfc2::engine::EntityRef NGfc2InternalPt::getSTDir()
{
    return ((Gfc2InternalPt*)m_pEntity)->getSTDir();
}

bool NGfc2InternalPt::hasSTDir()
{
    return ((Gfc2InternalPt*)m_pEntity)->hasSTDir();
}

NGfc2Vector2d^ NGfc2InternalPt::getSTDirPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2InternalPt*)m_pEntity)->getSTDirPtr(), false);
}


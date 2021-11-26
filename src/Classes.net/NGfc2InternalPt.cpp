#include "NGfc2InternalPt.h"

using namespace gfc::classes::x3;

NGfc2InternalPt::NGfc2InternalPt()
{
    m_pEntity = new Gfc2InternalPt;
    m_bOwner = true;
}

NGfc2InternalPt::NGfc2InternalPt(void* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

void NGfc2InternalPt::setP(gfc::engine::EntityRef nValue)
{
    ((Gfc2InternalPt*)m_pEntity)->setP(nValue);
}

gfc::engine::EntityRef NGfc2InternalPt::getP()
{
    return ((Gfc2InternalPt*)m_pEntity)->getP();
}

bool NGfc2InternalPt::hasP()
{
    return ((Gfc2InternalPt*)m_pEntity)->hasP();
}

void NGfc2InternalPt::setTVec(gfc::engine::EntityRef nValue)
{
    ((Gfc2InternalPt*)m_pEntity)->setTVec(nValue);
}

gfc::engine::EntityRef NGfc2InternalPt::getTVec()
{
    return ((Gfc2InternalPt*)m_pEntity)->getTVec();
}

bool NGfc2InternalPt::hasTVec()
{
    return ((Gfc2InternalPt*)m_pEntity)->hasTVec();
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

void NGfc2InternalPt::setUV(gfc::engine::EntityRef nValue)
{
    ((Gfc2InternalPt*)m_pEntity)->setUV(nValue);
}

gfc::engine::EntityRef NGfc2InternalPt::getUV()
{
    return ((Gfc2InternalPt*)m_pEntity)->getUV();
}

bool NGfc2InternalPt::hasUV()
{
    return ((Gfc2InternalPt*)m_pEntity)->hasUV();
}

void NGfc2InternalPt::setST(gfc::engine::EntityRef nValue)
{
    ((Gfc2InternalPt*)m_pEntity)->setST(nValue);
}

gfc::engine::EntityRef NGfc2InternalPt::getST()
{
    return ((Gfc2InternalPt*)m_pEntity)->getST();
}

bool NGfc2InternalPt::hasST()
{
    return ((Gfc2InternalPt*)m_pEntity)->hasST();
}

void NGfc2InternalPt::setUVDir(gfc::engine::EntityRef nValue)
{
    ((Gfc2InternalPt*)m_pEntity)->setUVDir(nValue);
}

gfc::engine::EntityRef NGfc2InternalPt::getUVDir()
{
    return ((Gfc2InternalPt*)m_pEntity)->getUVDir();
}

bool NGfc2InternalPt::hasUVDir()
{
    return ((Gfc2InternalPt*)m_pEntity)->hasUVDir();
}

void NGfc2InternalPt::setSTDir(gfc::engine::EntityRef nValue)
{
    ((Gfc2InternalPt*)m_pEntity)->setSTDir(nValue);
}

gfc::engine::EntityRef NGfc2InternalPt::getSTDir()
{
    return ((Gfc2InternalPt*)m_pEntity)->getSTDir();
}

bool NGfc2InternalPt::hasSTDir()
{
    return ((Gfc2InternalPt*)m_pEntity)->hasSTDir();
}


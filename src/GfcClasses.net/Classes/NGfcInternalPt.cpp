#include "NGfcInternalPt.h"

using namespace gfc::classes::x3;

NGfcInternalPt::NGfcInternalPt()
{
    m_pEntity = new GfcInternalPt;
    m_bOwner = true;
}

NGfcInternalPt::NGfcInternalPt(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcEntity(pEntity, bOwner)
{
}

void NGfcInternalPt::setP(gfc::engine::EntityRef nValue)
{
    ((GfcInternalPt*)m_pEntity)->setP(nValue);
}

gfc::engine::EntityRef NGfcInternalPt::getP()
{
    return ((GfcInternalPt*)m_pEntity)->getP();
}

bool NGfcInternalPt::hasP()
{
    return ((GfcInternalPt*)m_pEntity)->hasP();
}

void NGfcInternalPt::setTVec(gfc::engine::EntityRef nValue)
{
    ((GfcInternalPt*)m_pEntity)->setTVec(nValue);
}

gfc::engine::EntityRef NGfcInternalPt::getTVec()
{
    return ((GfcInternalPt*)m_pEntity)->getTVec();
}

bool NGfcInternalPt::hasTVec()
{
    return ((GfcInternalPt*)m_pEntity)->hasTVec();
}

void NGfcInternalPt::setT(NGfcDouble dValue)
{
    ((GfcInternalPt*)m_pEntity)->setT(dValue);
}

NGfcDouble NGfcInternalPt::getT()
{
    return ((GfcInternalPt*)m_pEntity)->getT();
}

bool NGfcInternalPt::hasT()
{
    return ((GfcInternalPt*)m_pEntity)->hasT();
}

void NGfcInternalPt::setUV(gfc::engine::EntityRef nValue)
{
    ((GfcInternalPt*)m_pEntity)->setUV(nValue);
}

gfc::engine::EntityRef NGfcInternalPt::getUV()
{
    return ((GfcInternalPt*)m_pEntity)->getUV();
}

bool NGfcInternalPt::hasUV()
{
    return ((GfcInternalPt*)m_pEntity)->hasUV();
}

void NGfcInternalPt::setST(gfc::engine::EntityRef nValue)
{
    ((GfcInternalPt*)m_pEntity)->setST(nValue);
}

gfc::engine::EntityRef NGfcInternalPt::getST()
{
    return ((GfcInternalPt*)m_pEntity)->getST();
}

bool NGfcInternalPt::hasST()
{
    return ((GfcInternalPt*)m_pEntity)->hasST();
}

void NGfcInternalPt::setUVDir(gfc::engine::EntityRef nValue)
{
    ((GfcInternalPt*)m_pEntity)->setUVDir(nValue);
}

gfc::engine::EntityRef NGfcInternalPt::getUVDir()
{
    return ((GfcInternalPt*)m_pEntity)->getUVDir();
}

bool NGfcInternalPt::hasUVDir()
{
    return ((GfcInternalPt*)m_pEntity)->hasUVDir();
}

void NGfcInternalPt::setSTDir(gfc::engine::EntityRef nValue)
{
    ((GfcInternalPt*)m_pEntity)->setSTDir(nValue);
}

gfc::engine::EntityRef NGfcInternalPt::getSTDir()
{
    return ((GfcInternalPt*)m_pEntity)->getSTDir();
}

bool NGfcInternalPt::hasSTDir()
{
    return ((GfcInternalPt*)m_pEntity)->hasSTDir();
}


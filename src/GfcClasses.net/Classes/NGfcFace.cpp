#include "NGfcFace.h"

using namespace gfc::classes::x3;

NGfcFace::NGfcFace()
{
    m_pEntity = new GfcFace;
    m_bOwner = true;
}

NGfcFace::NGfcFace(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcCommonPolygonEx(pEntity, bOwner)
{
}

void NGfcFace::setSurface(gfc::engine::EntityRef nValue)
{
    ((GfcFace*)m_pEntity)->setSurface(nValue);
}

gfc::engine::EntityRef NGfcFace::getSurface()
{
    return ((GfcFace*)m_pEntity)->getSurface();
}

bool NGfcFace::hasSurface()
{
    return ((GfcFace*)m_pEntity)->hasSurface();
}

void NGfcFace::setBox(gfc::engine::EntityRef nValue)
{
    ((GfcFace*)m_pEntity)->setBox(nValue);
}

gfc::engine::EntityRef NGfcFace::getBox()
{
    return ((GfcFace*)m_pEntity)->getBox();
}

bool NGfcFace::hasBox()
{
    return ((GfcFace*)m_pEntity)->hasBox();
}

void NGfcFace::setSameDir(NGfcBoolean bValue)
{
    ((GfcFace*)m_pEntity)->setSameDir(bValue);
}

NGfcBoolean NGfcFace::getSameDir()
{
    return ((GfcFace*)m_pEntity)->getSameDir();
}

bool NGfcFace::hasSameDir()
{
    return ((GfcFace*)m_pEntity)->hasSameDir();
}

void NGfcFace::setIndex(NGfcInteger nValue)
{
    ((GfcFace*)m_pEntity)->setIndex(nValue);
}

NGfcInteger NGfcFace::getIndex()
{
    return ((GfcFace*)m_pEntity)->getIndex();
}

bool NGfcFace::hasIndex()
{
    return ((GfcFace*)m_pEntity)->hasIndex();
}


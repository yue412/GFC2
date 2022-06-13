#include "NGfcRuledSurface.h"

using namespace gfc::classes::x3;

NGfcRuledSurface::NGfcRuledSurface()
{
    m_pEntity = new GfcRuledSurface;
    m_bOwner = true;
}

NGfcRuledSurface::NGfcRuledSurface(bool bNoCreate):
    NGfcSurface(bNoCreate)
{
}

void NGfcRuledSurface::setApexIndex(NGfcInteger nValue)
{
    ((GfcRuledSurface*)m_pEntity)->setApexIndex(nValue);
}

NGfcInteger NGfcRuledSurface::getApexIndex()
{
    return ((GfcRuledSurface*)m_pEntity)->getApexIndex();
}

bool NGfcRuledSurface::hasApexIndex()
{
    return ((GfcRuledSurface*)m_pEntity)->hasApexIndex();
}

void NGfcRuledSurface::setRangeV(gfc::engine::EntityRef nValue)
{
    ((GfcRuledSurface*)m_pEntity)->setRangeV(nValue);
}

gfc::engine::EntityRef NGfcRuledSurface::getRangeV()
{
    return ((GfcRuledSurface*)m_pEntity)->getRangeV();
}

bool NGfcRuledSurface::hasRangeV()
{
    return ((GfcRuledSurface*)m_pEntity)->hasRangeV();
}

void NGfcRuledSurface::setRangeU(gfc::engine::EntityRef nValue)
{
    ((GfcRuledSurface*)m_pEntity)->setRangeU(nValue);
}

gfc::engine::EntityRef NGfcRuledSurface::getRangeU()
{
    return ((GfcRuledSurface*)m_pEntity)->getRangeU();
}

bool NGfcRuledSurface::hasRangeU()
{
    return ((GfcRuledSurface*)m_pEntity)->hasRangeU();
}

void NGfcRuledSurface::setDirectrix1(gfc::engine::EntityRef nValue)
{
    ((GfcRuledSurface*)m_pEntity)->setDirectrix1(nValue);
}

gfc::engine::EntityRef NGfcRuledSurface::getDirectrix1()
{
    return ((GfcRuledSurface*)m_pEntity)->getDirectrix1();
}

bool NGfcRuledSurface::hasDirectrix1()
{
    return ((GfcRuledSurface*)m_pEntity)->hasDirectrix1();
}

void NGfcRuledSurface::setDirectrix2(gfc::engine::EntityRef nValue)
{
    ((GfcRuledSurface*)m_pEntity)->setDirectrix2(nValue);
}

gfc::engine::EntityRef NGfcRuledSurface::getDirectrix2()
{
    return ((GfcRuledSurface*)m_pEntity)->getDirectrix2();
}

bool NGfcRuledSurface::hasDirectrix2()
{
    return ((GfcRuledSurface*)m_pEntity)->hasDirectrix2();
}


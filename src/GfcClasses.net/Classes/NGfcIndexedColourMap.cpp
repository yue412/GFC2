#include "NGfcIndexedColourMap.h"

using namespace gfc::classes::x3;

NGfcIndexedColourMap::NGfcIndexedColourMap()
{
    m_pEntity = new GfcIndexedColourMap;
    m_bOwner = true;
}

NGfcIndexedColourMap::NGfcIndexedColourMap(bool bNoCreate):
    NGfcRoot(bNoCreate)
{
}

void NGfcIndexedColourMap::setOpacity(NGfcDouble dValue)
{
    ((GfcIndexedColourMap*)m_pEntity)->setOpacity(dValue);
}

NGfcDouble NGfcIndexedColourMap::getOpacity()
{
    return ((GfcIndexedColourMap*)m_pEntity)->getOpacity();
}

bool NGfcIndexedColourMap::hasOpacity()
{
    return ((GfcIndexedColourMap*)m_pEntity)->hasOpacity();
}

void NGfcIndexedColourMap::setColor(gfc::engine::EntityRef nValue)
{
    ((GfcIndexedColourMap*)m_pEntity)->setColor(nValue);
}

gfc::engine::EntityRef NGfcIndexedColourMap::getColor()
{
    return ((GfcIndexedColourMap*)m_pEntity)->getColor();
}

bool NGfcIndexedColourMap::hasColor()
{
    return ((GfcIndexedColourMap*)m_pEntity)->hasColor();
}

void NGfcIndexedColourMap::setMappedTo(gfc::engine::EntityRef nValue)
{
    ((GfcIndexedColourMap*)m_pEntity)->setMappedTo(nValue);
}

gfc::engine::EntityRef NGfcIndexedColourMap::getMappedTo()
{
    return ((GfcIndexedColourMap*)m_pEntity)->getMappedTo();
}

bool NGfcIndexedColourMap::hasMappedTo()
{
    return ((GfcIndexedColourMap*)m_pEntity)->hasMappedTo();
}


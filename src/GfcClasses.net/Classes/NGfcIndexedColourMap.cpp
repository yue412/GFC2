#include "NGfcIndexedColourMap.h"

using namespace gfc::classes::x3;

NGfcIndexedColourMap::NGfcIndexedColourMap()
{
    m_pEntity = new GfcIndexedColourMap;
    m_bOwner = true;
}

NGfcIndexedColourMap::NGfcIndexedColourMap(bool bNoCreate):
    NEntity(bNoCreate)
{
}

void NGfcIndexedColourMap::setTransparency(NGfcDouble dValue)
{
    ((GfcIndexedColourMap*)m_pEntity)->setTransparency(dValue);
}

NGfcDouble NGfcIndexedColourMap::getTransparency()
{
    return ((GfcIndexedColourMap*)m_pEntity)->getTransparency();
}

bool NGfcIndexedColourMap::hasTransparency()
{
    return ((GfcIndexedColourMap*)m_pEntity)->hasTransparency();
}

int NGfcIndexedColourMap::getColoursCount()
{
    return ((GfcIndexedColourMap*)m_pEntity)->getColoursCount();
}

void NGfcIndexedColourMap::clearColours()
{
    ((GfcIndexedColourMap*)m_pEntity)->clearColours();
}

void NGfcIndexedColourMap::addColours(gfc::engine::EntityRef nValue)
{
    ((GfcIndexedColourMap*)m_pEntity)->addColours(nValue);
}

gfc::engine::EntityRef NGfcIndexedColourMap::getColours(int nIndex)
{
    return ((GfcIndexedColourMap*)m_pEntity)->getColours(nIndex);
}

int NGfcIndexedColourMap::getColourIndexCount()
{
    return ((GfcIndexedColourMap*)m_pEntity)->getColourIndexCount();
}

void NGfcIndexedColourMap::clearColourIndex()
{
    ((GfcIndexedColourMap*)m_pEntity)->clearColourIndex();
}

void NGfcIndexedColourMap::addColourIndex(NGfcInteger nValue)
{
    ((GfcIndexedColourMap*)m_pEntity)->addColourIndex(nValue);
}

NGfcInteger NGfcIndexedColourMap::getColourIndex(int nIndex)
{
    return ((GfcIndexedColourMap*)m_pEntity)->getColourIndex(nIndex);
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


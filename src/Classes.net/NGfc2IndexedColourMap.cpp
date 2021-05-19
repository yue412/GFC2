#include "StdAfx.h"
#include "NGfc2IndexedColourMap.h"
NGfc2IndexedColourMap::NGfc2IndexedColourMap()
{
    m_pEntity = new Gfc2IndexedColourMap;
    m_bOwner = true;
}

NGfc2IndexedColourMap::NGfc2IndexedColourMap(void* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

void NGfc2IndexedColourMap::setTransparency(NGfc2Double dValue)
{
    ((Gfc2IndexedColourMap*)m_pEntity)->setTransparency(dValue);
}

NGfc2Double NGfc2IndexedColourMap::getTransparency()
{
    return ((Gfc2IndexedColourMap*)m_pEntity)->getTransparency();
}

bool NGfc2IndexedColourMap::hasTransparency()
{
    return ((Gfc2IndexedColourMap*)m_pEntity)->hasTransparency();
}

int NGfc2IndexedColourMap::getColoursCount()
{
    return ((Gfc2IndexedColourMap*)m_pEntity)->getColoursCount();
}

void NGfc2IndexedColourMap::clearColours()
{
    ((Gfc2IndexedColourMap*)m_pEntity)->clearColours();
}

void NGfc2IndexedColourMap::addColours(gfc::engine::EntityRef nValue)
{
    ((Gfc2IndexedColourMap*)m_pEntity)->addColours(nValue);
}

gfc::engine::EntityRef NGfc2IndexedColourMap::getColours(int nIndex)
{
    return ((Gfc2IndexedColourMap*)m_pEntity)->getColours(nIndex);
}

NGfc2Color^ NGfc2IndexedColourMap::getColoursPtr(int nIndex)
{
    return gcnew NGfc2Color(((Gfc2IndexedColourMap*)m_pEntity)->getColoursPtr(nIndex), false);
}

int NGfc2IndexedColourMap::getColourIndexCount()
{
    return ((Gfc2IndexedColourMap*)m_pEntity)->getColourIndexCount();
}

void NGfc2IndexedColourMap::clearColourIndex()
{
    ((Gfc2IndexedColourMap*)m_pEntity)->clearColourIndex();
}

void NGfc2IndexedColourMap::addColourIndex(NGfc2Integer nValue)
{
    ((Gfc2IndexedColourMap*)m_pEntity)->addColourIndex(nValue);
}

NGfc2Integer NGfc2IndexedColourMap::getColourIndex(int nIndex)
{
    return ((Gfc2IndexedColourMap*)m_pEntity)->getColourIndex(nIndex);
}

void NGfc2IndexedColourMap::setMappedTo(gfc::engine::EntityRef nValue)
{
    ((Gfc2IndexedColourMap*)m_pEntity)->setMappedTo(nValue);
}

gfc::engine::EntityRef NGfc2IndexedColourMap::getMappedTo()
{
    return ((Gfc2IndexedColourMap*)m_pEntity)->getMappedTo();
}

bool NGfc2IndexedColourMap::hasMappedTo()
{
    return ((Gfc2IndexedColourMap*)m_pEntity)->hasMappedTo();
}

NGfc2PrimitiveRenderable^ NGfc2IndexedColourMap::getMappedToPtr()
{
    return gcnew NGfc2PrimitiveRenderable(((Gfc2IndexedColourMap*)m_pEntity)->getMappedToPtr(), false);
}


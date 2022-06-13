#include "NGfcIndexedTextureMap.h"

using namespace gfc::classes::x3;

NGfcIndexedTextureMap::NGfcIndexedTextureMap()
{
    m_pEntity = new GfcIndexedTextureMap;
    m_bOwner = true;
}

NGfcIndexedTextureMap::NGfcIndexedTextureMap(bool bNoCreate):
    NEntity(bNoCreate)
{
}

void NGfcIndexedTextureMap::setMappedTo(gfc::engine::EntityRef nValue)
{
    ((GfcIndexedTextureMap*)m_pEntity)->setMappedTo(nValue);
}

gfc::engine::EntityRef NGfcIndexedTextureMap::getMappedTo()
{
    return ((GfcIndexedTextureMap*)m_pEntity)->getMappedTo();
}

bool NGfcIndexedTextureMap::hasMappedTo()
{
    return ((GfcIndexedTextureMap*)m_pEntity)->hasMappedTo();
}

int NGfcIndexedTextureMap::getTexCoordsCount()
{
    return ((GfcIndexedTextureMap*)m_pEntity)->getTexCoordsCount();
}

void NGfcIndexedTextureMap::clearTexCoords()
{
    ((GfcIndexedTextureMap*)m_pEntity)->clearTexCoords();
}

void NGfcIndexedTextureMap::addTexCoords(gfc::engine::EntityRef nValue)
{
    ((GfcIndexedTextureMap*)m_pEntity)->addTexCoords(nValue);
}

gfc::engine::EntityRef NGfcIndexedTextureMap::getTexCoords(int nIndex)
{
    return ((GfcIndexedTextureMap*)m_pEntity)->getTexCoords(nIndex);
}

int NGfcIndexedTextureMap::getTexCoordIndexCount()
{
    return ((GfcIndexedTextureMap*)m_pEntity)->getTexCoordIndexCount();
}

void NGfcIndexedTextureMap::clearTexCoordIndex()
{
    ((GfcIndexedTextureMap*)m_pEntity)->clearTexCoordIndex();
}

void NGfcIndexedTextureMap::addTexCoordIndex(NGfcInteger nValue)
{
    ((GfcIndexedTextureMap*)m_pEntity)->addTexCoordIndex(nValue);
}

NGfcInteger NGfcIndexedTextureMap::getTexCoordIndex(int nIndex)
{
    return ((GfcIndexedTextureMap*)m_pEntity)->getTexCoordIndex(nIndex);
}

int NGfcIndexedTextureMap::getMapsCount()
{
    return ((GfcIndexedTextureMap*)m_pEntity)->getMapsCount();
}

void NGfcIndexedTextureMap::clearMaps()
{
    ((GfcIndexedTextureMap*)m_pEntity)->clearMaps();
}

void NGfcIndexedTextureMap::addMaps(gfc::engine::EntityRef nValue)
{
    ((GfcIndexedTextureMap*)m_pEntity)->addMaps(nValue);
}

gfc::engine::EntityRef NGfcIndexedTextureMap::getMaps(int nIndex)
{
    return ((GfcIndexedTextureMap*)m_pEntity)->getMaps(nIndex);
}


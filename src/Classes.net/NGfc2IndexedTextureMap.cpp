#include "StdAfx.h"
#include "NGfc2IndexedTextureMap.h"
NGfc2IndexedTextureMap::NGfc2IndexedTextureMap()
{
    m_pEntity = new Gfc2IndexedTextureMap;
    m_bOwner = true;
}

NGfc2IndexedTextureMap::NGfc2IndexedTextureMap(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2IndexedTextureMap::setMappedTo(gfc::engine::EntityRef nValue)
{
    ((Gfc2IndexedTextureMap*)m_pEntity)->setMappedTo(nValue);
}

gfc::engine::EntityRef NGfc2IndexedTextureMap::getMappedTo()
{
    return ((Gfc2IndexedTextureMap*)m_pEntity)->getMappedTo();
}

bool NGfc2IndexedTextureMap::hasMappedTo()
{
    return ((Gfc2IndexedTextureMap*)m_pEntity)->hasMappedTo();
}

NGfc2PrimitiveRenderable^ NGfc2IndexedTextureMap::getMappedToPtr()
{
    return gcnew NGfc2PrimitiveRenderable(((Gfc2IndexedTextureMap*)m_pEntity)->getMappedToPtr(), false);
}

int NGfc2IndexedTextureMap::getTexCoordsCount()
{
    return ((Gfc2IndexedTextureMap*)m_pEntity)->getTexCoordsCount();
}

void NGfc2IndexedTextureMap::clearTexCoords()
{
    ((Gfc2IndexedTextureMap*)m_pEntity)->clearTexCoords();
}

void NGfc2IndexedTextureMap::addTexCoords(gfc::engine::EntityRef nValue)
{
    ((Gfc2IndexedTextureMap*)m_pEntity)->addTexCoords(nValue);
}

gfc::engine::EntityRef NGfc2IndexedTextureMap::getTexCoords(int nIndex)
{
    return ((Gfc2IndexedTextureMap*)m_pEntity)->getTexCoords(nIndex);
}

NGfc2Vector2d^ NGfc2IndexedTextureMap::getTexCoordsPtr(int nIndex)
{
    return gcnew NGfc2Vector2d(((Gfc2IndexedTextureMap*)m_pEntity)->getTexCoordsPtr(nIndex), false);
}

int NGfc2IndexedTextureMap::getTexCoordIndexCount()
{
    return ((Gfc2IndexedTextureMap*)m_pEntity)->getTexCoordIndexCount();
}

void NGfc2IndexedTextureMap::clearTexCoordIndex()
{
    ((Gfc2IndexedTextureMap*)m_pEntity)->clearTexCoordIndex();
}

void NGfc2IndexedTextureMap::addTexCoordIndex(NGfc2Integer nValue)
{
    ((Gfc2IndexedTextureMap*)m_pEntity)->addTexCoordIndex(nValue);
}

NGfc2Integer NGfc2IndexedTextureMap::getTexCoordIndex(int nIndex)
{
    return ((Gfc2IndexedTextureMap*)m_pEntity)->getTexCoordIndex(nIndex);
}

int NGfc2IndexedTextureMap::getMapsCount()
{
    return ((Gfc2IndexedTextureMap*)m_pEntity)->getMapsCount();
}

void NGfc2IndexedTextureMap::clearMaps()
{
    ((Gfc2IndexedTextureMap*)m_pEntity)->clearMaps();
}

void NGfc2IndexedTextureMap::addMaps(gfc::engine::EntityRef nValue)
{
    ((Gfc2IndexedTextureMap*)m_pEntity)->addMaps(nValue);
}

gfc::engine::EntityRef NGfc2IndexedTextureMap::getMaps(int nIndex)
{
    return ((Gfc2IndexedTextureMap*)m_pEntity)->getMaps(nIndex);
}

NGfc2SurfaceTexture^ NGfc2IndexedTextureMap::getMapsPtr(int nIndex)
{
    return gcnew NGfc2SurfaceTexture(((Gfc2IndexedTextureMap*)m_pEntity)->getMapsPtr(nIndex), false);
}


#include "NGfcIndexedTextureMap.h"

using namespace gfc::classes::x3;

NGfcIndexedTextureMap::NGfcIndexedTextureMap()
{
    m_pEntity = new GfcIndexedTextureMap;
    m_bOwner = true;
}

NGfcIndexedTextureMap::NGfcIndexedTextureMap(bool bNoCreate):
    NGfcRoot(bNoCreate)
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

void NGfcIndexedTextureMap::setMaterial(gfc::engine::EntityRef nValue)
{
    ((GfcIndexedTextureMap*)m_pEntity)->setMaterial(nValue);
}

gfc::engine::EntityRef NGfcIndexedTextureMap::getMaterial()
{
    return ((GfcIndexedTextureMap*)m_pEntity)->getMaterial();
}

bool NGfcIndexedTextureMap::hasMaterial()
{
    return ((GfcIndexedTextureMap*)m_pEntity)->hasMaterial();
}

int NGfcIndexedTextureMap::getCoordListCount()
{
    return ((GfcIndexedTextureMap*)m_pEntity)->getCoordListCount();
}

void NGfcIndexedTextureMap::clearCoordList()
{
    ((GfcIndexedTextureMap*)m_pEntity)->clearCoordList();
}

void NGfcIndexedTextureMap::addCoordList(gfc::engine::EntityRef nValue)
{
    ((GfcIndexedTextureMap*)m_pEntity)->addCoordList(nValue);
}

gfc::engine::EntityRef NGfcIndexedTextureMap::getCoordList(int nIndex)
{
    return ((GfcIndexedTextureMap*)m_pEntity)->getCoordList(nIndex);
}


#ifndef NGFC2INDEXEDTEXTUREMAP_H
#define NGFC2INDEXEDTEXTUREMAP_H

#include "Gfc2IndexedTextureMap.h"
#include "NGfc2PrimitiveRenderable.h"
#include "NGfc2Vector2d.h"
#include "NGfc2SurfaceTexture.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2IndexedTextureMap: public glodon::objectbufnet::Entity
{
public:
    NGfc2IndexedTextureMap();
    NGfc2IndexedTextureMap(void* pEntity, bool bOwner);
    void setMappedTo(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getMappedTo();
    bool hasMappedTo();
    NGfc2PrimitiveRenderable^ getMappedToPtr();
    int getTexCoordsCount();
    void clearTexCoords();
    void addTexCoords(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getTexCoords(int nIndex);
    NGfc2Vector2d^ getTexCoordsPtr(int nIndex);
    int getTexCoordIndexCount();
    void clearTexCoordIndex();
    void addTexCoordIndex(NGfc2Integer nValue);
    NGfc2Integer getTexCoordIndex(int nIndex);
    int getMapsCount();
    void clearMaps();
    void addMaps(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getMaps(int nIndex);
    NGfc2SurfaceTexture^ getMapsPtr(int nIndex);

};
#endif

#ifndef NGFC2INDEXEDTEXTUREMAP_H
#define NGFC2INDEXEDTEXTUREMAP_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2IndexedTextureMap.h"
#include "NGfc2PrimitiveRenderable.h"
#include "NGfc2Vector2d.h"
#include "NGfc2SurfaceTexture.h"
#include "NTypeDef.h"

public ref class NGfc2IndexedTextureMap: public NGfc2Root
{
public:
    NGfc2IndexedTextureMap();
    NGfc2IndexedTextureMap(gfc::engine::CEntity* pEntity, bool bOwner);
    void setMappedTo(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMappedTo();
    bool hasMappedTo();
    int getTexCoordsCount();
    void clearTexCoords();
    void addTexCoords(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getTexCoords(int nIndex);
    int getTexCoordIndexCount();
    void clearTexCoordIndex();
    void addTexCoordIndex(NGfc2Integer nValue);
    NGfc2Integer getTexCoordIndex(int nIndex);
    int getMapsCount();
    void clearMaps();
    void addMaps(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMaps(int nIndex);

};
#endif

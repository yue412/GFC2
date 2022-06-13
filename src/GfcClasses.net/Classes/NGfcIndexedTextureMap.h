#ifndef NGFCINDEXEDTEXTUREMAP_H
#define NGFCINDEXEDTEXTUREMAP_H

#include "NEntity.h"
#include "GfcClasses\x3\GfcIndexedTextureMap.h"
#include "NGfcPrimitiveRenderable.h"
#include "NGfcVector2d.h"
#include "NGfcSurfaceTexture.h"
#include "NTypeDef.h"

public ref class NGfcIndexedTextureMap: public NEntity
{
public:
    NGfcIndexedTextureMap();
    NGfcIndexedTextureMap(bool bNoCreate);
    void setMappedTo(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMappedTo();
    bool hasMappedTo();
    int getTexCoordsCount();
    void clearTexCoords();
    void addTexCoords(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getTexCoords(int nIndex);
    int getTexCoordIndexCount();
    void clearTexCoordIndex();
    void addTexCoordIndex(NGfcInteger nValue);
    NGfcInteger getTexCoordIndex(int nIndex);
    int getMapsCount();
    void clearMaps();
    void addMaps(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMaps(int nIndex);

};
#endif

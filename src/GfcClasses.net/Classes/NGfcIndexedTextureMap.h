#ifndef NGFCINDEXEDTEXTUREMAP_H
#define NGFCINDEXEDTEXTUREMAP_H

#include "NGfcRoot.h"
#include "GfcClasses\x3\GfcIndexedTextureMap.h"
#include "NGfcTriangulatedFaceSet.h"
#include "NGfcAppearanceMaterial.h"
#include "NGfcTextureCoordList.h"

public ref class NGfcIndexedTextureMap: public NGfcRoot
{
public:
    NGfcIndexedTextureMap();
    NGfcIndexedTextureMap(bool bNoCreate);
    void setMappedTo(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMappedTo();
    bool hasMappedTo();
    void setMaterial(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMaterial();
    bool hasMaterial();
    int getCoordListCount();
    void clearCoordList();
    void addCoordList(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoordList(int nIndex);

};
#endif

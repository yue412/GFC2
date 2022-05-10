#ifndef GFCINDEXEDTEXTUREMAP_H
#define GFCINDEXEDTEXTUREMAP_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcPrimitiveRenderable.h"
#include "GfcClasses/x3/GfcVector2d.h"
#include "GfcClasses/x3/GfcSurfaceTexture.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcIndexedTextureMap: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcIndexedTextureMap, gfc::engine::CEntity)
public:
    GfcIndexedTextureMap();
    GfcIndexedTextureMap(bool bSetSchema);
    void setMappedTo(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getMappedTo() const;
    bool hasMappedTo() const;
    std::shared_ptr<GfcPrimitiveRenderable> getMappedToPtr();
    int getTexCoordsCount() const;
    void clearTexCoords();
    void addTexCoords(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getTexCoords(int nIndex) const;
    std::shared_ptr<GfcVector2d> getTexCoordsPtr(int nIndex);
    int getTexCoordIndexCount() const;
    void clearTexCoordIndex();
    void addTexCoordIndex(const GfcInteger& nValue);
    GfcInteger getTexCoordIndex(int nIndex) const;
    int getMapsCount() const;
    void clearMaps();
    void addMaps(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getMaps(int nIndex) const;
    std::shared_ptr<GfcSurfaceTexture> getMapsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif

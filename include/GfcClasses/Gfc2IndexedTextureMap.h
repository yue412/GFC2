#ifndef GFC2INDEXEDTEXTUREMAP_H
#define GFC2INDEXEDTEXTUREMAP_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2PrimitiveRenderable.h"
#include "Gfc2Vector2d.h"
#include "Gfc2SurfaceTexture.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2IndexedTextureMap: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2IndexedTextureMap,gfc2::engine::EntityFactory)
public:
    Gfc2IndexedTextureMap();
    Gfc2IndexedTextureMap(bool bSetSchema);
    void setMappedTo(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getMappedTo() const;
    bool hasMappedTo() const;
    std::shared_ptr<Gfc2PrimitiveRenderable> getMappedToPtr();
    int getTexCoordsCount() const;
    void clearTexCoords();
    void addTexCoords(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getTexCoords(int nIndex) const;
    std::shared_ptr<Gfc2Vector2d> getTexCoordsPtr(int nIndex);
    int getTexCoordIndexCount() const;
    void clearTexCoordIndex();
    void addTexCoordIndex(const Gfc2Integer& nValue);
    Gfc2Integer getTexCoordIndex(int nIndex) const;
    int getMapsCount() const;
    void clearMaps();
    void addMaps(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getMaps(int nIndex) const;
    std::shared_ptr<Gfc2SurfaceTexture> getMapsPtr(int nIndex);

};
#endif

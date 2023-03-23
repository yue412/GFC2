#ifndef GFCINDEXEDTEXTUREMAP_H
#define GFCINDEXEDTEXTUREMAP_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRoot.h"
#include "GfcClasses/x3/GfcTriangulatedFaceSet.h"
#include "GfcClasses/x3/GfcMaterial.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcIndexedTextureMap: public GfcRoot
{
GFCENGINE_DEC_OBJECT(GfcIndexedTextureMap, gfc::engine::CEntity)
public:
    GfcIndexedTextureMap();
    GfcIndexedTextureMap(bool bSetSchema);
    void setMappedTo(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getMappedTo() const;
    bool hasMappedTo() const;
    std::shared_ptr<GfcTriangulatedFaceSet> getMappedToPtr();
    int getTexCoordsCount() const;
    void clearTexCoords();
    void addTexCoords(const GfcDouble& dValue);
    GfcDouble getTexCoords(int nIndex) const;
    int getTexCoordIndexCount() const;
    void clearTexCoordIndex();
    void addTexCoordIndex(const GfcInteger& nValue);
    GfcInteger getTexCoordIndex(int nIndex) const;
    int getMaterialsCount() const;
    void clearMaterials();
    void addMaterials(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getMaterials(int nIndex) const;
    std::shared_ptr<GfcMaterial> getMaterialsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif

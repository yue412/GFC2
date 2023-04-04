#ifndef GFCINDEXEDTEXTUREMAP_H
#define GFCINDEXEDTEXTUREMAP_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRoot.h"
#include "GfcClasses/x3/GfcTriangulatedFaceSet.h"
#include "GfcClasses/x3/GfcAppearanceMaterial.h"
#include "GfcClasses/x3/GfcTextureCoordList.h"
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
    void setMaterial(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getMaterial() const;
    bool hasMaterial() const;
    std::shared_ptr<GfcAppearanceMaterial> getMaterialPtr();
    int getCoordListCount() const;
    void clearCoordList();
    void addCoordList(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoordList(int nIndex) const;
    std::shared_ptr<GfcTextureCoordList> getCoordListPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif

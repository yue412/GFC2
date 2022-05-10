#ifndef GFCPRIMITIVERENDERABLE_H
#define GFCPRIMITIVERENDERABLE_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRepresentationItem.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPrimitiveRenderable: public GfcRepresentationItem
{
GFCENGINE_DEC_OBJECT(GfcPrimitiveRenderable, gfc::engine::CEntity)
public:
    GfcPrimitiveRenderable();
    GfcPrimitiveRenderable(bool bSetSchema);
    void setPrimitiveType(const GfcPrimitiveType& nValue);
    GfcPrimitiveType getPrimitiveType() const;
    bool hasPrimitiveType() const;
    void setGeometryDataType(const GfcGeometryDataType& nValue);
    GfcGeometryDataType getGeometryDataType() const;
    bool hasGeometryDataType() const;
    void setExtension(const GfcString& sValue);
    GfcString getExtension() const;
    bool hasExtension() const;
    int getVertexesCount() const;
    void clearVertexes();
    void addVertexes(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getVertexes(int nIndex) const;
    std::shared_ptr<GfcVector3d> getVertexesPtr(int nIndex);
    int getNormalsCount() const;
    void clearNormals();
    void addNormals(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getNormals(int nIndex) const;
    std::shared_ptr<GfcVector3d> getNormalsPtr(int nIndex);
    int getIndexesCount() const;
    void clearIndexes();
    void addIndexes(const GfcInteger& nValue);
    GfcInteger getIndexes(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif

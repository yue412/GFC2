#ifndef GFC2PRIMITIVERENDERABLE_H
#define GFC2PRIMITIVERENDERABLE_H

#include "GfcClasses.h"
#include "Gfc2RepresentationItem.h"
#include "Gfc2Vector3d.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2PrimitiveRenderable: public Gfc2RepresentationItem
{
GFCENGINE_DEC_OBJECT(Gfc2PrimitiveRenderable, gfc::engine::CEntity)
public:
    Gfc2PrimitiveRenderable();
    Gfc2PrimitiveRenderable(bool bSetSchema);
    void setPrimitiveType(const Gfc2PrimitiveType& nValue);
    Gfc2PrimitiveType getPrimitiveType() const;
    bool hasPrimitiveType() const;
    void setGeometryDataType(const Gfc2GeometryDataType& nValue);
    Gfc2GeometryDataType getGeometryDataType() const;
    bool hasGeometryDataType() const;
    void setExtension(const Gfc2String& sValue);
    Gfc2String getExtension() const;
    bool hasExtension() const;
    int getVertexesCount() const;
    void clearVertexes();
    void addVertexes(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getVertexes(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Vector3d> getVertexesPtr(int nIndex);
    int getNormalsCount() const;
    void clearNormals();
    void addNormals(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getNormals(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Vector3d> getNormalsPtr(int nIndex);
    int getIndexesCount() const;
    void clearIndexes();
    void addIndexes(const Gfc2Integer& nValue);
    Gfc2Integer getIndexes(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif

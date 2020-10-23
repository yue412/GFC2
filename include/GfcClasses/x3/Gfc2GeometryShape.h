#ifndef GFC2GEOMETRYSHAPE_H
#define GFC2GEOMETRYSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Shape.h"
#include "GfcClasses/x3/Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2GeometryShape: public Gfc2Shape
{
GFCENGINE_DEC_OBJECT(Gfc2GeometryShape, gfc::engine::CEntity)
public:
    Gfc2GeometryShape();
    Gfc2GeometryShape(bool bSetSchema);
    int getGeosCount() const;
    void clearGeos();
    void addGeos(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getGeos(int nIndex) const;
    std::shared_ptr<Gfc2Geometry> getGeosPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif

#ifndef GFC2GEOMETRYSHAPE_H
#define GFC2GEOMETRYSHAPE_H

#include "GfcClasses.h"
#include "Gfc2Shape.h"
#include "Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2GeometryShape: public Gfc2Shape
{
GFCENGINE_DEC_OBJECT(Gfc2GeometryShape, gfc2::engine::Entity)
public:
    Gfc2GeometryShape();
    Gfc2GeometryShape(bool bSetSchema);
    int getGeosCount() const;
    void clearGeos();
    void addGeos(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getGeos(int nIndex) const;
    std::shared_ptr<Gfc2Geometry> getGeosPtr(int nIndex);

};
#endif

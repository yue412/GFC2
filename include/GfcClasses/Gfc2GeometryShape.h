#ifndef GFC2GEOMETRYSHAPE_H
#define GFC2GEOMETRYSHAPE_H

#include "GfcClasses.h"
#include "Gfc2Shape.h"
#include "Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

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
    gfc::engine::CEntityWrapPtr<Gfc2Geometry> getGeosPtr(int nIndex);

};
#endif

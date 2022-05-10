#ifndef GFCGEOMETRYSHAPE_H
#define GFCGEOMETRYSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcShape.h"
#include "GfcClasses/x3/GfcGeometry.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcGeometryShape: public GfcShape
{
GFCENGINE_DEC_OBJECT(GfcGeometryShape, gfc::engine::CEntity)
public:
    GfcGeometryShape();
    GfcGeometryShape(bool bSetSchema);
    int getGeosCount() const;
    void clearGeos();
    void addGeos(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getGeos(int nIndex) const;
    std::shared_ptr<GfcGeometry> getGeosPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif

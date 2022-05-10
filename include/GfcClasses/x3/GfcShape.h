#ifndef GFCSHAPE_H
#define GFCSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcCoordinates3d.h"
#include "GfcClasses/x3/GfcBox3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcShape: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcShape, gfc::engine::CEntity)
public:
    GfcShape();
    GfcShape(bool bSetSchema);
    void setLocalCoordinate(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLocalCoordinate() const;
    bool hasLocalCoordinate() const;
    std::shared_ptr<GfcCoordinates3d> getLocalCoordinatePtr();
    void setBoundingBox(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getBoundingBox() const;
    bool hasBoundingBox() const;
    std::shared_ptr<GfcBox3d> getBoundingBoxPtr();

};

GFCCLASSES_NAMESPACE_END

#endif

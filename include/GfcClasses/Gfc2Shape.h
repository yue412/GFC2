#ifndef GFC2SHAPE_H
#define GFC2SHAPE_H

#include "GfcClasses.h"
#include "Gfc2Coordinates3d.h"
#include "Gfc2Box3d.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Shape: public gfc::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2Shape, gfc::engine::Entity)
public:
    Gfc2Shape();
    Gfc2Shape(bool bSetSchema);
    void setLocalCoordinate(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLocalCoordinate() const;
    bool hasLocalCoordinate() const;
    std::shared_ptr<Gfc2Coordinates3d> getLocalCoordinatePtr();
    void setBoundingBox(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getBoundingBox() const;
    bool hasBoundingBox() const;
    std::shared_ptr<Gfc2Box3d> getBoundingBoxPtr();

};
#endif

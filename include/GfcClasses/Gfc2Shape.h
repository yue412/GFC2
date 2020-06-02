#ifndef GFC2SHAPE_H
#define GFC2SHAPE_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Coordinates3d.h"
#include "Gfc2Box3d.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Shape: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2Shape,gfc2::engine::EntityFactory)
public:
    Gfc2Shape();
    Gfc2Shape(bool bSetSchema);
    void setLocalCoordinate(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getLocalCoordinate() const;
    bool hasLocalCoordinate() const;
    std::shared_ptr<Gfc2Coordinates3d> getLocalCoordinatePtr();
    void setBoundingBox(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getBoundingBox() const;
    bool hasBoundingBox() const;
    std::shared_ptr<Gfc2Box3d> getBoundingBoxPtr();

};
#endif

#ifndef NGFC2SHAPE_H
#define NGFC2SHAPE_H

#include "Gfc2Shape.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Box3d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Shape: public glodon::objectbufnet::Entity
{
public:
    NGfc2Shape();
    NGfc2Shape(void* pEntity, bool bOwner);
    void setLocalCoordinate(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getLocalCoordinate();
    bool hasLocalCoordinate();
    NGfc2Coordinates3d^ getLocalCoordinatePtr();
    void setBoundingBox(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getBoundingBox();
    bool hasBoundingBox();
    NGfc2Box3d^ getBoundingBoxPtr();

};
#endif

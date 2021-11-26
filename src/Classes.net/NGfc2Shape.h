#ifndef NGFC2SHAPE_H
#define NGFC2SHAPE_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2Shape.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Box3d.h"

public ref class NGfc2Shape: public NGfc2Root
{
public:
    NGfc2Shape();
    NGfc2Shape(void* pEntity, bool bOwner);
    void setLocalCoordinate(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getLocalCoordinate();
    bool hasLocalCoordinate();
    void setBoundingBox(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getBoundingBox();
    bool hasBoundingBox();

};
#endif

#ifndef NGFC2COORDINATES3D_H
#define NGFC2COORDINATES3D_H

#include "NGfc2Geometry.h"
#include "GfcClasses\x3\Gfc2Coordinates3d.h"
#include "NGfc2Vector3d.h"

public ref class NGfc2Coordinates3d: public NGfc2Geometry
{
public:
    NGfc2Coordinates3d();
    NGfc2Coordinates3d(void* pEntity, bool bOwner);
    void setOrigin(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getOrigin();
    bool hasOrigin();
    void setX(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getX();
    bool hasX();
    void setY(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getY();
    bool hasY();
    void setZ(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getZ();
    bool hasZ();

};
#endif

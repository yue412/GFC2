#ifndef NGFC2COORDINATES3D_H
#define NGFC2COORDINATES3D_H

#include "NGfc2Geometry.h"
#include "Gfc2Coordinates3d.h"
#include "NGfc2Vector3d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Coordinates3d: public NGfc2Geometry
{
public:
    NGfc2Coordinates3d();
    NGfc2Coordinates3d(void* pEntity, bool bOwner);
    void setOrigin(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getOrigin();
    bool hasOrigin();
    NGfc2Vector3d^ getOriginPtr();
    void setX(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getX();
    bool hasX();
    NGfc2Vector3d^ getXPtr();
    void setY(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getY();
    bool hasY();
    NGfc2Vector3d^ getYPtr();
    void setZ(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getZ();
    bool hasZ();
    NGfc2Vector3d^ getZPtr();

};
#endif

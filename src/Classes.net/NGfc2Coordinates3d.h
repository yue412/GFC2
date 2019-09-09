#ifndef NGFC2COORDINATES3D_H
#define NGFC2COORDINATES3D_H

#include "NGfc2Geometry.h"
#include "Gfc2Coordinates3d.h"
#include "NGfc2Vector3d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Coordinates3d: public NGfc2Geometry
{
public:
    NGfc2Coordinates3d();
    NGfc2Coordinates3d(void* pEntity, bool bOwner);
    void setOrigin(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getOrigin();
    bool hasOrigin();
    NGfc2Vector3d^ getOriginPtr();
    void setX(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getX();
    bool hasX();
    NGfc2Vector3d^ getXPtr();
    void setY(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getY();
    bool hasY();
    NGfc2Vector3d^ getYPtr();
    void setZ(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getZ();
    bool hasZ();
    NGfc2Vector3d^ getZPtr();

};
#endif

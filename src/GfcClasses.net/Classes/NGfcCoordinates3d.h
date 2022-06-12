#ifndef NGFCCOORDINATES3D_H
#define NGFCCOORDINATES3D_H

#include "NGfcGeometry.h"
#include "GfcClasses\x3\GfcCoordinates3d.h"
#include "NGfcVector3d.h"

public ref class NGfcCoordinates3d: public NGfcGeometry
{
public:
    NGfcCoordinates3d();
    NGfcCoordinates3d(gfc::engine::CEntity* pEntity, bool bOwner);
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

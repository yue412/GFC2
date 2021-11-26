#ifndef NGFC2COORDINATES2D_H
#define NGFC2COORDINATES2D_H

#include "NGfc2Geometry.h"
#include "GfcClasses\x3\Gfc2Coordinates2d.h"
#include "NGfc2Vector2d.h"

public ref class NGfc2Coordinates2d: public NGfc2Geometry
{
public:
    NGfc2Coordinates2d();
    NGfc2Coordinates2d(void* pEntity, bool bOwner);
    void setOrigin(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getOrigin();
    bool hasOrigin();
    void setX(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getX();
    bool hasX();
    void setY(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getY();
    bool hasY();

};
#endif

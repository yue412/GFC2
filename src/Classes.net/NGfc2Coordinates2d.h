#ifndef NGFC2COORDINATES2D_H
#define NGFC2COORDINATES2D_H

#include "NGfc2Geometry.h"
#include "Gfc2Coordinates2d.h"
#include "NGfc2Vector2d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Coordinates2d: public NGfc2Geometry
{
public:
    NGfc2Coordinates2d();
    NGfc2Coordinates2d(void* pEntity, bool bOwner);
    void setOrigin(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getOrigin();
    bool hasOrigin();
    NGfc2Vector2d^ getOriginPtr();
    void setX(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getX();
    bool hasX();
    NGfc2Vector2d^ getXPtr();
    void setY(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getY();
    bool hasY();
    NGfc2Vector2d^ getYPtr();

};
#endif

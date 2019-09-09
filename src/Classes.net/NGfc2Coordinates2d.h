#ifndef NGFC2COORDINATES2D_H
#define NGFC2COORDINATES2D_H

#include "NGfc2Geometry.h"
#include "Gfc2Coordinates2d.h"
#include "NGfc2Vector2d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Coordinates2d: public NGfc2Geometry
{
public:
    NGfc2Coordinates2d();
    NGfc2Coordinates2d(void* pEntity, bool bOwner);
    void setOrigin(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getOrigin();
    bool hasOrigin();
    NGfc2Vector2d^ getOriginPtr();
    void setX(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getX();
    bool hasX();
    NGfc2Vector2d^ getXPtr();
    void setY(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getY();
    bool hasY();
    NGfc2Vector2d^ getYPtr();

};
#endif

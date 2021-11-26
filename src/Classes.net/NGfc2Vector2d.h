#ifndef NGFC2VECTOR2D_H
#define NGFC2VECTOR2D_H

#include "NGfc2Geometry.h"
#include "GfcClasses\x3\Gfc2Vector2d.h"
#include "NTypeDef.h"

public ref class NGfc2Vector2d: public NGfc2Geometry
{
public:
    NGfc2Vector2d();
    NGfc2Vector2d(gfc::engine::CEntity* pEntity, bool bOwner);
    void setX(NGfc2Double dValue);
    NGfc2Double getX();
    bool hasX();
    void setY(NGfc2Double dValue);
    NGfc2Double getY();
    bool hasY();

};
#endif

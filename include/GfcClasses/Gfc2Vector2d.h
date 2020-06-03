#ifndef GFC2VECTOR2D_H
#define GFC2VECTOR2D_H

#include "GfcClasses.h"
#include "Gfc2Geometry.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Vector2d: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Vector2d, gfc::engine::Entity)
public:
    Gfc2Vector2d();
    Gfc2Vector2d(bool bSetSchema);
    void setX(const Gfc2Double& dValue);
    Gfc2Double getX() const;
    bool hasX() const;
    void setY(const Gfc2Double& dValue);
    Gfc2Double getY() const;
    bool hasY() const;

};
#endif

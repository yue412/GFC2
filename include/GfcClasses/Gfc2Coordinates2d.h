#ifndef GFC2COORDINATES2D_H
#define GFC2COORDINATES2D_H

#include "GfcClasses.h"
#include "Gfc2Geometry.h"
#include "Gfc2Vector2d.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Coordinates2d: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Coordinates2d, gfc2::engine::Entity)
public:
    Gfc2Coordinates2d();
    Gfc2Coordinates2d(bool bSetSchema);
    void setOrigin(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getOrigin() const;
    bool hasOrigin() const;
    std::shared_ptr<Gfc2Vector2d> getOriginPtr();
    void setX(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getX() const;
    bool hasX() const;
    std::shared_ptr<Gfc2Vector2d> getXPtr();
    void setY(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getY() const;
    bool hasY() const;
    std::shared_ptr<Gfc2Vector2d> getYPtr();

};
#endif

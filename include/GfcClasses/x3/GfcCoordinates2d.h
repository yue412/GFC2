#ifndef GFCCOORDINATES2D_H
#define GFCCOORDINATES2D_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcGeometry.h"
#include "GfcClasses/x3/GfcVector2d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCoordinates2d: public GfcGeometry
{
GFCENGINE_DEC_OBJECT(GfcCoordinates2d, gfc::engine::CEntity)
public:
    GfcCoordinates2d();
    GfcCoordinates2d(bool bSetSchema);
    void setOrigin(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getOrigin() const;
    bool hasOrigin() const;
    std::shared_ptr<GfcVector2d> getOriginPtr();
    void setX(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getX() const;
    bool hasX() const;
    std::shared_ptr<GfcVector2d> getXPtr();
    void setY(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getY() const;
    bool hasY() const;
    std::shared_ptr<GfcVector2d> getYPtr();

};

GFCCLASSES_NAMESPACE_END

#endif

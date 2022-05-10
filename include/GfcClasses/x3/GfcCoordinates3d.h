#ifndef GFCCOORDINATES3D_H
#define GFCCOORDINATES3D_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcGeometry.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCoordinates3d: public GfcGeometry
{
GFCENGINE_DEC_OBJECT(GfcCoordinates3d, gfc::engine::CEntity)
public:
    GfcCoordinates3d();
    GfcCoordinates3d(bool bSetSchema);
    void setOrigin(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getOrigin() const;
    bool hasOrigin() const;
    std::shared_ptr<GfcVector3d> getOriginPtr();
    void setX(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getX() const;
    bool hasX() const;
    std::shared_ptr<GfcVector3d> getXPtr();
    void setY(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getY() const;
    bool hasY() const;
    std::shared_ptr<GfcVector3d> getYPtr();
    void setZ(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getZ() const;
    bool hasZ() const;
    std::shared_ptr<GfcVector3d> getZPtr();

};

GFCCLASSES_NAMESPACE_END

#endif

#ifndef GFC2COORDINATES3D_H
#define GFC2COORDINATES3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Geometry.h"
#include "GfcClasses/x3/Gfc2Vector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Coordinates3d: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Coordinates3d, gfc::engine::CEntity)
public:
    Gfc2Coordinates3d();
    Gfc2Coordinates3d(bool bSetSchema);
    void setOrigin(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getOrigin() const;
    bool hasOrigin() const;
    std::shared_ptr<Gfc2Vector3d> getOriginPtr();
    void setX(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getX() const;
    bool hasX() const;
    std::shared_ptr<Gfc2Vector3d> getXPtr();
    void setY(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getY() const;
    bool hasY() const;
    std::shared_ptr<Gfc2Vector3d> getYPtr();
    void setZ(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getZ() const;
    bool hasZ() const;
    std::shared_ptr<Gfc2Vector3d> getZPtr();

};

GFCCLASSES_NAMESPACE_END

#endif

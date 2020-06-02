#ifndef GFC2COORDINATES3D_H
#define GFC2COORDINATES3D_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Geometry.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Coordinates3d: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Coordinates3d,gfc2::engine::EntityFactory)
public:
    Gfc2Coordinates3d();
    Gfc2Coordinates3d(bool bSetSchema);
    void setOrigin(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getOrigin() const;
    bool hasOrigin() const;
    std::shared_ptr<Gfc2Vector3d> getOriginPtr();
    void setX(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getX() const;
    bool hasX() const;
    std::shared_ptr<Gfc2Vector3d> getXPtr();
    void setY(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getY() const;
    bool hasY() const;
    std::shared_ptr<Gfc2Vector3d> getYPtr();
    void setZ(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getZ() const;
    bool hasZ() const;
    std::shared_ptr<Gfc2Vector3d> getZPtr();

};
#endif

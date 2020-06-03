#ifndef GFC2CYLINDER_H
#define GFC2CYLINDER_H

#include "GfcClasses.h"
#include "Gfc2Surface.h"
#include "Gfc2Intervald.h"
#include "Gfc2Curve2d.h"
#include "Gfc2Vector3d.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Cylinder: public Gfc2Surface
{
GFCENGINE_DEC_OBJECT(Gfc2Cylinder, gfc::engine::Entity)
public:
    Gfc2Cylinder();
    Gfc2Cylinder(bool bSetSchema);
    void setRangeV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeV() const;
    bool hasRangeV() const;
    std::shared_ptr<Gfc2Intervald> getRangeVPtr();
    void setCurve(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCurve() const;
    bool hasCurve() const;
    std::shared_ptr<Gfc2Curve2d> getCurvePtr();
    void setDirX(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirX() const;
    bool hasDirX() const;
    std::shared_ptr<Gfc2Vector3d> getDirXPtr();
    void setDirY(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirY() const;
    bool hasDirY() const;
    std::shared_ptr<Gfc2Vector3d> getDirYPtr();
    void setDirZ(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirZ() const;
    bool hasDirZ() const;
    std::shared_ptr<Gfc2Vector3d> getDirZPtr();
    void setPos(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPos() const;
    bool hasPos() const;
    std::shared_ptr<Gfc2Vector3d> getPosPtr();

};
#endif

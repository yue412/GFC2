#ifndef GFC2CYLINDER_H
#define GFC2CYLINDER_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Surface.h"
#include "Gfc2Intervald.h"
#include "Gfc2Curve2d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Cylinder: public Gfc2Surface
{
GFCENGINE_DEC_OBJECT(Gfc2Cylinder,gfc2::engine::EntityFactory)
public:
    Gfc2Cylinder();
    Gfc2Cylinder(bool bSetSchema);
    void setRangeV(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRangeV() const;
    bool hasRangeV() const;
    std::shared_ptr<Gfc2Intervald> getRangeVPtr();
    void setCurve(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getCurve() const;
    bool hasCurve() const;
    std::shared_ptr<Gfc2Curve2d> getCurvePtr();
    void setDirX(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getDirX() const;
    bool hasDirX() const;
    std::shared_ptr<Gfc2Vector3d> getDirXPtr();
    void setDirY(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getDirY() const;
    bool hasDirY() const;
    std::shared_ptr<Gfc2Vector3d> getDirYPtr();
    void setDirZ(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getDirZ() const;
    bool hasDirZ() const;
    std::shared_ptr<Gfc2Vector3d> getDirZPtr();
    void setPos(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getPos() const;
    bool hasPos() const;
    std::shared_ptr<Gfc2Vector3d> getPosPtr();

};
#endif

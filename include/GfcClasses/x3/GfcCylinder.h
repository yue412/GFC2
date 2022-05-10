#ifndef GFCCYLINDER_H
#define GFCCYLINDER_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSurface.h"
#include "GfcClasses/x3/GfcIntervald.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCylinder: public GfcSurface
{
GFCENGINE_DEC_OBJECT(GfcCylinder, gfc::engine::CEntity)
public:
    GfcCylinder();
    GfcCylinder(bool bSetSchema);
    void setRangeV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeV() const;
    bool hasRangeV() const;
    std::shared_ptr<GfcIntervald> getRangeVPtr();
    void setCurve(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCurve() const;
    bool hasCurve() const;
    std::shared_ptr<GfcCurve2d> getCurvePtr();
    void setDirX(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirX() const;
    bool hasDirX() const;
    std::shared_ptr<GfcVector3d> getDirXPtr();
    void setDirY(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirY() const;
    bool hasDirY() const;
    std::shared_ptr<GfcVector3d> getDirYPtr();
    void setDirZ(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirZ() const;
    bool hasDirZ() const;
    std::shared_ptr<GfcVector3d> getDirZPtr();
    void setPos(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPos() const;
    bool hasPos() const;
    std::shared_ptr<GfcVector3d> getPosPtr();

};

GFCCLASSES_NAMESPACE_END

#endif

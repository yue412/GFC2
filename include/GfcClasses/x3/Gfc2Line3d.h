#ifndef GFC2LINE3D_H
#define GFC2LINE3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Curve3d.h"
#include "GfcClasses/x3/Gfc2Vector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Line3d: public Gfc2Curve3d
{
GFCENGINE_DEC_OBJECT(Gfc2Line3d, gfc::engine::CEntity)
public:
    Gfc2Line3d();
    Gfc2Line3d(bool bSetSchema);
    void setStartPt(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getStartPt() const;
    bool hasStartPt() const;
    std::shared_ptr<Gfc2Vector3d> getStartPtPtr();
    void setEndPt(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getEndPt() const;
    bool hasEndPt() const;
    std::shared_ptr<Gfc2Vector3d> getEndPtPtr();

};

GFCCLASSES_NAMESPACE_END

#endif

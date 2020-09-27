#ifndef GFC2PLANECURVE3D_H
#define GFC2PLANECURVE3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Curve3d.h"
#include "GfcClasses/x3/Gfc2Curve2d.h"
#include "GfcClasses/x3/Gfc2PlaneInfo.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2PlaneCurve3d: public Gfc2Curve3d
{
GFCENGINE_DEC_OBJECT(Gfc2PlaneCurve3d, gfc::engine::CEntity)
public:
    Gfc2PlaneCurve3d();
    Gfc2PlaneCurve3d(bool bSetSchema);
    void setPlaneCurve(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPlaneCurve() const;
    bool hasPlaneCurve() const;
    gfc::engine::CEntityWrapPtr<Gfc2Curve2d> getPlaneCurvePtr();
    void setPlane(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPlane() const;
    bool hasPlane() const;
    gfc::engine::CEntityWrapPtr<Gfc2PlaneInfo> getPlanePtr();

};

GFCCLASSES_NAMESPACE_END

#endif

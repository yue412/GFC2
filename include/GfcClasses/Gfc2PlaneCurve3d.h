#ifndef GFC2PLANECURVE3D_H
#define GFC2PLANECURVE3D_H

#include "GfcClasses.h"
#include "Gfc2Curve3d.h"
#include "Gfc2Curve2d.h"
#include "Gfc2PlaneInfo.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2PlaneCurve3d: public Gfc2Curve3d
{
GFCENGINE_DEC_OBJECT(Gfc2PlaneCurve3d, gfc2::engine::Entity)
public:
    Gfc2PlaneCurve3d();
    Gfc2PlaneCurve3d(bool bSetSchema);
    void setPlaneCurve(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getPlaneCurve() const;
    bool hasPlaneCurve() const;
    std::shared_ptr<Gfc2Curve2d> getPlaneCurvePtr();
    void setPlane(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getPlane() const;
    bool hasPlane() const;
    std::shared_ptr<Gfc2PlaneInfo> getPlanePtr();

};
#endif

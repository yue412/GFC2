#ifndef GFCPLANECURVE3D_H
#define GFCPLANECURVE3D_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcCurve3d.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcClasses/x3/GfcPlaneInfo.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPlaneCurve3d: public GfcCurve3d
{
GFCENGINE_DEC_OBJECT(GfcPlaneCurve3d, gfc::engine::CEntity)
public:
    GfcPlaneCurve3d();
    GfcPlaneCurve3d(bool bSetSchema);
    void setPlaneCurve(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPlaneCurve() const;
    bool hasPlaneCurve() const;
    std::shared_ptr<GfcCurve2d> getPlaneCurvePtr();
    void setPlane(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPlane() const;
    bool hasPlane() const;
    std::shared_ptr<GfcPlaneInfo> getPlanePtr();

};

GFCCLASSES_NAMESPACE_END

#endif

#ifndef NGFC2PLANECURVE3D_H
#define NGFC2PLANECURVE3D_H

#include "NGfc2Curve3d.h"
#include "Gfc2PlaneCurve3d.h"
#include "NGfc2Curve2d.h"
#include "NGfc2PlaneInfo.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2PlaneCurve3d: public NGfc2Curve3d
{
public:
    NGfc2PlaneCurve3d();
    NGfc2PlaneCurve3d(void* pEntity, bool bOwner);
    void setPlaneCurve(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getPlaneCurve();
    bool hasPlaneCurve();
    NGfc2Curve2d^ getPlaneCurvePtr();
    void setPlane(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getPlane();
    bool hasPlane();
    NGfc2PlaneInfo^ getPlanePtr();

};
#endif

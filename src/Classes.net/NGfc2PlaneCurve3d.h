#ifndef NGFC2PLANECURVE3D_H
#define NGFC2PLANECURVE3D_H

#include "NGfc2Curve3d.h"
#include "GfcClasses\x3\Gfc2PlaneCurve3d.h"
#include "NGfc2Curve2d.h"
#include "NGfc2PlaneInfo.h"

public ref class NGfc2PlaneCurve3d: public NGfc2Curve3d
{
public:
    NGfc2PlaneCurve3d();
    NGfc2PlaneCurve3d(gfc::engine::CEntity* pEntity, bool bOwner);
    void setPlaneCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPlaneCurve();
    bool hasPlaneCurve();
    void setPlane(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPlane();
    bool hasPlane();

};
#endif

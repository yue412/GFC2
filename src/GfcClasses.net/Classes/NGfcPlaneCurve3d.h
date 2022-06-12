#ifndef NGFCPLANECURVE3D_H
#define NGFCPLANECURVE3D_H

#include "NGfcCurve3d.h"
#include "GfcClasses\x3\GfcPlaneCurve3d.h"
#include "NGfcCurve2d.h"
#include "NGfcPlaneInfo.h"

public ref class NGfcPlaneCurve3d: public NGfcCurve3d
{
public:
    NGfcPlaneCurve3d();
    NGfcPlaneCurve3d(gfc::engine::CEntity* pEntity, bool bOwner);
    void setPlaneCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPlaneCurve();
    bool hasPlaneCurve();
    void setPlane(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPlane();
    bool hasPlane();

};
#endif

#ifndef NGFCLINE3D_H
#define NGFCLINE3D_H

#include "NGfcCurve3d.h"
#include "GfcClasses\x3\GfcLine3d.h"
#include "NGfcVector3d.h"

public ref class NGfcLine3d: public NGfcCurve3d
{
public:
    NGfcLine3d();
    NGfcLine3d(gfc::engine::CEntity* pEntity, bool bOwner);
    void setStartPt(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getStartPt();
    bool hasStartPt();
    void setEndPt(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getEndPt();
    bool hasEndPt();

};
#endif

#ifndef NGFC2LINE3D_H
#define NGFC2LINE3D_H

#include "NGfc2Curve3d.h"
#include "GfcClasses\x3\Gfc2Line3d.h"
#include "NGfc2Vector3d.h"

public ref class NGfc2Line3d: public NGfc2Curve3d
{
public:
    NGfc2Line3d();
    NGfc2Line3d(gfc::engine::CEntity* pEntity, bool bOwner);
    void setStartPt(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getStartPt();
    bool hasStartPt();
    void setEndPt(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getEndPt();
    bool hasEndPt();

};
#endif

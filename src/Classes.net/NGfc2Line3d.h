#ifndef NGFC2LINE3D_H
#define NGFC2LINE3D_H

#include "NGfc2Curve3d.h"
#include "Gfc2Line3d.h"
#include "NGfc2Vector3d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Line3d: public NGfc2Curve3d
{
public:
    NGfc2Line3d();
    NGfc2Line3d(void* pEntity, bool bOwner);
    void setStartPt(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getStartPt();
    bool hasStartPt();
    NGfc2Vector3d^ getStartPtPtr();
    void setEndPt(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getEndPt();
    bool hasEndPt();
    NGfc2Vector3d^ getEndPtPtr();

};
#endif

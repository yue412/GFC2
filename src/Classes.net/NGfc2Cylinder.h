#ifndef NGFC2CYLINDER_H
#define NGFC2CYLINDER_H

#include "NGfc2Surface.h"
#include "GfcClasses\x3\Gfc2Cylinder.h"
#include "NGfc2Intervald.h"
#include "NGfc2Curve2d.h"
#include "NGfc2Vector3d.h"

public ref class NGfc2Cylinder: public NGfc2Surface
{
public:
    NGfc2Cylinder();
    NGfc2Cylinder(void* pEntity, bool bOwner);
    void setRangeV(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRangeV();
    bool hasRangeV();
    void setCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurve();
    bool hasCurve();
    void setDirX(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirX();
    bool hasDirX();
    void setDirY(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirY();
    bool hasDirY();
    void setDirZ(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirZ();
    bool hasDirZ();
    void setPos(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPos();
    bool hasPos();

};
#endif

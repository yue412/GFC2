#ifndef NGFC2CYLINDER_H
#define NGFC2CYLINDER_H

#include "NGfc2Surface.h"
#include "Gfc2Cylinder.h"
#include "NGfc2Intervald.h"
#include "NGfc2Curve2d.h"
#include "NGfc2Vector3d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Cylinder: public NGfc2Surface
{
public:
    NGfc2Cylinder();
    NGfc2Cylinder(void* pEntity, bool bOwner);
    void setRangeV(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getRangeV();
    bool hasRangeV();
    NGfc2Intervald^ getRangeVPtr();
    void setCurve(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getCurve();
    bool hasCurve();
    NGfc2Curve2d^ getCurvePtr();
    void setDirX(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getDirX();
    bool hasDirX();
    NGfc2Vector3d^ getDirXPtr();
    void setDirY(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getDirY();
    bool hasDirY();
    NGfc2Vector3d^ getDirYPtr();
    void setDirZ(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getDirZ();
    bool hasDirZ();
    NGfc2Vector3d^ getDirZPtr();
    void setPos(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getPos();
    bool hasPos();
    NGfc2Vector3d^ getPosPtr();

};
#endif

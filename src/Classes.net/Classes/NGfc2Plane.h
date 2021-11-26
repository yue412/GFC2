#ifndef NGFC2PLANE_H
#define NGFC2PLANE_H

#include "NGfc2Surface.h"
#include "GfcClasses\x3\Gfc2Plane.h"
#include "NGfc2Vector3d.h"
#include "NGfc2Intervald.h"

public ref class NGfc2Plane: public NGfc2Surface
{
public:
    NGfc2Plane();
    NGfc2Plane(gfc::engine::CEntity* pEntity, bool bOwner);
    void setPos(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPos();
    bool hasPos();
    void setDirU(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirU();
    bool hasDirU();
    void setDirV(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirV();
    bool hasDirV();
    void setRangeU(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRangeU();
    bool hasRangeU();
    void setRangeV(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRangeV();
    bool hasRangeV();

};
#endif

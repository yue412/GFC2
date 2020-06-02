#ifndef NGFC2PLANE_H
#define NGFC2PLANE_H

#include "NGfc2Surface.h"
#include "Gfc2Plane.h"
#include "NGfc2Vector3d.h"
#include "NGfc2Intervald.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Plane: public NGfc2Surface
{
public:
    NGfc2Plane();
    NGfc2Plane(void* pEntity, bool bOwner);
    void setPos(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getPos();
    bool hasPos();
    NGfc2Vector3d^ getPosPtr();
    void setDirU(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getDirU();
    bool hasDirU();
    NGfc2Vector3d^ getDirUPtr();
    void setDirV(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getDirV();
    bool hasDirV();
    NGfc2Vector3d^ getDirVPtr();
    void setRangeU(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getRangeU();
    bool hasRangeU();
    NGfc2Intervald^ getRangeUPtr();
    void setRangeV(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getRangeV();
    bool hasRangeV();
    NGfc2Intervald^ getRangeVPtr();

};
#endif

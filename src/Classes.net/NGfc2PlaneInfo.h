#ifndef NGFC2PLANEINFO_H
#define NGFC2PLANEINFO_H

#include "NGfc2Root.h"
#include "Gfc2PlaneInfo.h"
#include "NGfc2Vector3d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2PlaneInfo: public NGfc2Root
{
public:
    NGfc2PlaneInfo();
    NGfc2PlaneInfo(void* pEntity, bool bOwner);
    void setDirX(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirX();
    bool hasDirX();
    NGfc2Vector3d^ getDirXPtr();
    void setDirY(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirY();
    bool hasDirY();
    NGfc2Vector3d^ getDirYPtr();
    void setPos(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPos();
    bool hasPos();
    NGfc2Vector3d^ getPosPtr();

};
#endif

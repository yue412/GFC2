#ifndef NGFC2PLANEINFO_H
#define NGFC2PLANEINFO_H

#include "Gfc2PlaneInfo.h"
#include "NGfc2Vector3d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2PlaneInfo: public glodon::objectbufnet::Entity
{
public:
    NGfc2PlaneInfo();
    NGfc2PlaneInfo(void* pEntity, bool bOwner);
    void setDirX(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getDirX();
    bool hasDirX();
    NGfc2Vector3d^ getDirXPtr();
    void setDirY(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getDirY();
    bool hasDirY();
    NGfc2Vector3d^ getDirYPtr();
    void setPos(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getPos();
    bool hasPos();
    NGfc2Vector3d^ getPosPtr();

};
#endif

#ifndef NGFC2PLANEINFO_H
#define NGFC2PLANEINFO_H

#include "Gfc2PlaneInfo.h"
#include "NGfc2Vector3d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2PlaneInfo: public glodon::objectbufnet::Entity
{
public:
    NGfc2PlaneInfo();
    NGfc2PlaneInfo(void* pEntity, bool bOwner);
    void setDirX(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getDirX();
    bool hasDirX();
    NGfc2Vector3d^ getDirXPtr();
    void setDirY(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getDirY();
    bool hasDirY();
    NGfc2Vector3d^ getDirYPtr();
    void setPos(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getPos();
    bool hasPos();
    NGfc2Vector3d^ getPosPtr();

};
#endif

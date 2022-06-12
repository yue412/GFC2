#ifndef NGFCPLANEINFO_H
#define NGFCPLANEINFO_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcPlaneInfo.h"
#include "NGfcVector3d.h"

public ref class NGfcPlaneInfo: public NGfcEntity
{
public:
    NGfcPlaneInfo();
    NGfcPlaneInfo(gfc::engine::CEntity* pEntity, bool bOwner);
    void setDirX(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirX();
    bool hasDirX();
    void setDirY(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirY();
    bool hasDirY();
    void setPos(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPos();
    bool hasPos();

};
#endif

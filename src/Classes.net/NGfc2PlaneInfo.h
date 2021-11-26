#ifndef NGFC2PLANEINFO_H
#define NGFC2PLANEINFO_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2PlaneInfo.h"
#include "NGfc2Vector3d.h"

public ref class NGfc2PlaneInfo: public NGfc2Root
{
public:
    NGfc2PlaneInfo();
    NGfc2PlaneInfo(gfc::engine::CEntity* pEntity, bool bOwner);
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

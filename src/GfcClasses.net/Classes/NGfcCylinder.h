#ifndef NGFCCYLINDER_H
#define NGFCCYLINDER_H

#include "NGfcSurface.h"
#include "GfcClasses\x3\GfcCylinder.h"
#include "NGfcIntervald.h"
#include "NGfcCurve2d.h"
#include "NGfcVector3d.h"

public ref class NGfcCylinder: public NGfcSurface
{
public:
    NGfcCylinder();
    NGfcCylinder(gfc::engine::CEntity* pEntity, bool bOwner);
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

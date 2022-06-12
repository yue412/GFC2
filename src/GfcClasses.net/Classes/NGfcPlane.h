#ifndef NGFCPLANE_H
#define NGFCPLANE_H

#include "NGfcSurface.h"
#include "GfcClasses\x3\GfcPlane.h"
#include "NGfcVector3d.h"
#include "NGfcIntervald.h"

public ref class NGfcPlane: public NGfcSurface
{
public:
    NGfcPlane();
    NGfcPlane(gfc::engine::CEntity* pEntity, bool bOwner);
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

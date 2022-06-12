#ifndef NGFCTORUS_H
#define NGFCTORUS_H

#include "NGfcSurface.h"
#include "GfcClasses\x3\GfcTorus.h"
#include "NGfcCoordinates3d.h"
#include "NGfcIntervald.h"
#include "NGfcCurve2d.h"
#include "NTypeDef.h"

public ref class NGfcTorus: public NGfcSurface
{
public:
    NGfcTorus();
    NGfcTorus(gfc::engine::CEntity* pEntity, bool bOwner);
    void setCoord(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoord();
    bool hasCoord();
    void setRadius(NGfcDouble dValue);
    NGfcDouble getRadius();
    bool hasRadius();
    void setClockSign(NGfcInteger nValue);
    NGfcInteger getClockSign();
    bool hasClockSign();
    void setRangeV(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRangeV();
    bool hasRangeV();
    void setCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurve();
    bool hasCurve();

};
#endif

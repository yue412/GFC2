#ifndef NGFCBEVEL_H
#define NGFCBEVEL_H

#include "NGfcSurface.h"
#include "GfcClasses\x3\GfcBevel.h"
#include "NGfcCoordinates3d.h"
#include "NGfcIntervald.h"
#include "NGfcCurve2d.h"
#include "NTypeDef.h"

public ref class NGfcBevel: public NGfcSurface
{
public:
    NGfcBevel();
    NGfcBevel(gfc::engine::CEntity* pEntity, bool bOwner);
    void setCoord(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoord();
    bool hasCoord();
    void setHeight(NGfcDouble dValue);
    NGfcDouble getHeight();
    bool hasHeight();
    void setRangeV(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRangeV();
    bool hasRangeV();
    void setCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurve();
    bool hasCurve();

};
#endif

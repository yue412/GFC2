#ifndef NGFCSPIRALLINE2D_H
#define NGFCSPIRALLINE2D_H

#include "NGfcCurve2d.h"
#include "GfcClasses\x3\GfcSpiralLine2d.h"
#include "NGfcCoordinates2d.h"
#include "NGfcIntervald.h"
#include "NTypeDef.h"

public ref class NGfcSpiralLine2d: public NGfcCurve2d
{
public:
    NGfcSpiralLine2d();
    NGfcSpiralLine2d(bool bNoCreate);
    void setCoord(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoord();
    bool hasCoord();
    void setRadius(NGfcDouble dValue);
    NGfcDouble getRadius();
    bool hasRadius();
    void setRange(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRange();
    bool hasRange();
    void setClockSign(NGfcInteger nValue);
    NGfcInteger getClockSign();
    bool hasClockSign();
    void setRadiusCoef(NGfcDouble dValue);
    NGfcDouble getRadiusCoef();
    bool hasRadiusCoef();

};
#endif

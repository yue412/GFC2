#ifndef NGFCSPIRALLINE3D_H
#define NGFCSPIRALLINE3D_H

#include "NGfcCurve3d.h"
#include "GfcClasses\x3\GfcSpiralLine3d.h"
#include "NGfcCoordinates3d.h"
#include "NGfcIntervald.h"
#include "NTypeDef.h"

public ref class NGfcSpiralLine3d: public NGfcCurve3d
{
public:
    NGfcSpiralLine3d();
    NGfcSpiralLine3d(bool bNoCreate);
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
    void setHeightCoef(NGfcDouble dValue);
    NGfcDouble getHeightCoef();
    bool hasHeightCoef();
    void setRadiusCoef(NGfcDouble dValue);
    NGfcDouble getRadiusCoef();
    bool hasRadiusCoef();

};
#endif

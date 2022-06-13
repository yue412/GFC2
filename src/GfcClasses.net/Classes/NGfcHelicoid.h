#ifndef NGFCHELICOID_H
#define NGFCHELICOID_H

#include "NGfcSurface.h"
#include "GfcClasses\x3\GfcHelicoid.h"
#include "NGfcCoordinates3d.h"
#include "NGfcIntervald.h"
#include "NGfcCurve2d.h"
#include "NTypeDef.h"

public ref class NGfcHelicoid: public NGfcSurface
{
public:
    NGfcHelicoid();
    NGfcHelicoid(bool bNoCreate);
    void setCoord(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoord();
    bool hasCoord();
    void setRadius(NGfcDouble dValue);
    NGfcDouble getRadius();
    bool hasRadius();
    void setRangeV(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRangeV();
    bool hasRangeV();
    void setClockSign(NGfcInteger nValue);
    NGfcInteger getClockSign();
    bool hasClockSign();
    void setHeightCoef(NGfcDouble dValue);
    NGfcDouble getHeightCoef();
    bool hasHeightCoef();
    void setRadiusCoef(NGfcDouble dValue);
    NGfcDouble getRadiusCoef();
    bool hasRadiusCoef();
    void setCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurve();
    bool hasCurve();

};
#endif

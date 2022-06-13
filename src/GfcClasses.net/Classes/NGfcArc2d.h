#ifndef NGFCARC2D_H
#define NGFCARC2D_H

#include "NGfcCurve2d.h"
#include "GfcClasses\x3\GfcArc2d.h"
#include "NGfcVector2d.h"
#include "NGfcIntervald.h"
#include "NTypeDef.h"

public ref class NGfcArc2d: public NGfcCurve2d
{
public:
    NGfcArc2d();
    NGfcArc2d(bool bNoCreate);
    void setCenterPt(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCenterPt();
    bool hasCenterPt();
    void setRadius(NGfcDouble dValue);
    NGfcDouble getRadius();
    bool hasRadius();
    void setRange(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRange();
    bool hasRange();
    void setClockSign(NGfcInteger nValue);
    NGfcInteger getClockSign();
    bool hasClockSign();

};
#endif

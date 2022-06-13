#ifndef NGFCOFFSETCURVE2D_H
#define NGFCOFFSETCURVE2D_H

#include "NGfcCurve2d.h"
#include "GfcClasses\x3\GfcOffsetCurve2d.h"
#include "NTypeDef.h"

public ref class NGfcOffsetCurve2d: public NGfcCurve2d
{
public:
    NGfcOffsetCurve2d();
    NGfcOffsetCurve2d(bool bNoCreate);
    void setOffDist(NGfcDouble dValue);
    NGfcDouble getOffDist();
    bool hasOffDist();
    void setInitCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getInitCurve();
    bool hasInitCurve();

};
#endif

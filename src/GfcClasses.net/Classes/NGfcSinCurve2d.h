#ifndef NGFCSINCURVE2D_H
#define NGFCSINCURVE2D_H

#include "NGfcCurve2d.h"
#include "GfcClasses\x3\GfcSinCurve2d.h"
#include "NGfcVector2d.h"
#include "NGfcIntervald.h"
#include "NTypeDef.h"

public ref class NGfcSinCurve2d: public NGfcCurve2d
{
public:
    NGfcSinCurve2d();
    NGfcSinCurve2d(bool bNoCreate);
    void setPos(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPos();
    bool hasPos();
    void setDirX(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirX();
    bool hasDirX();
    void setA(NGfcDouble dValue);
    NGfcDouble getA();
    bool hasA();
    void setB(NGfcDouble dValue);
    NGfcDouble getB();
    bool hasB();
    void setRange(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRange();
    bool hasRange();
    void setClockSign(NGfcInteger nValue);
    NGfcInteger getClockSign();
    bool hasClockSign();

};
#endif

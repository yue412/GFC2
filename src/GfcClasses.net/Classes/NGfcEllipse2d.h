#ifndef NGFCELLIPSE2D_H
#define NGFCELLIPSE2D_H

#include "NGfcCurve2d.h"
#include "GfcClasses\x3\GfcEllipse2d.h"
#include "NGfcVector2d.h"
#include "NGfcIntervald.h"
#include "NTypeDef.h"

public ref class NGfcEllipse2d: public NGfcCurve2d
{
public:
    NGfcEllipse2d();
    NGfcEllipse2d(bool bNoCreate);
    void setCenterPt(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCenterPt();
    bool hasCenterPt();
    void setMajorAxis(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMajorAxis();
    bool hasMajorAxis();
    void setdMajorRad(NGfcDouble dValue);
    NGfcDouble getdMajorRad();
    bool hasdMajorRad();
    void setdMinorRad(NGfcDouble dValue);
    NGfcDouble getdMinorRad();
    bool hasdMinorRad();
    void setRange(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRange();
    bool hasRange();
    void setClockSign(NGfcInteger nValue);
    NGfcInteger getClockSign();
    bool hasClockSign();

};
#endif

#ifndef NGFCLINE2D_H
#define NGFCLINE2D_H

#include "NGfcCurve2d.h"
#include "GfcClasses\x3\GfcLine2d.h"
#include "NGfcVector2d.h"

public ref class NGfcLine2d: public NGfcCurve2d
{
public:
    NGfcLine2d();
    NGfcLine2d(bool bNoCreate);
    void setStartPt(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getStartPt();
    bool hasStartPt();
    void setEndPt(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getEndPt();
    bool hasEndPt();

};
#endif

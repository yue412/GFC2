#ifndef NGFC2PREIMAGECURVE2D_H
#define NGFC2PREIMAGECURVE2D_H

#include "NGfc2Curve2d.h"
#include "GfcClasses\x3\Gfc2PreimageCurve2d.h"
#include "NGfc2Intervald.h"
#include "NGfc2Surface.h"
#include "NGfc2Curve3d.h"
#include "NTypeDef.h"

public ref class NGfc2PreimageCurve2d: public NGfc2Curve2d
{
public:
    NGfc2PreimageCurve2d();
    NGfc2PreimageCurve2d(void* pEntity, bool bOwner);
    void setRange(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRange();
    bool hasRange();
    void setReversed(NGfc2Boolean bValue);
    NGfc2Boolean getReversed();
    bool hasReversed();
    void setBase(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getBase();
    bool hasBase();
    void setCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurve();
    bool hasCurve();
    void setTolerance(NGfc2Double dValue);
    NGfc2Double getTolerance();
    bool hasTolerance();

};
#endif

#ifndef NGFC2PREIMAGECURVE2D_H
#define NGFC2PREIMAGECURVE2D_H

#include "NGfc2Curve2d.h"
#include "Gfc2PreimageCurve2d.h"
#include "NGfc2Intervald.h"
#include "NGfc2Surface.h"
#include "NGfc2Curve3d.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2PreimageCurve2d: public NGfc2Curve2d
{
public:
    NGfc2PreimageCurve2d();
    NGfc2PreimageCurve2d(void* pEntity, bool bOwner);
    void setRange(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getRange();
    bool hasRange();
    NGfc2Intervald^ getRangePtr();
    void setReversed(NGfc2Boolean bValue);
    NGfc2Boolean getReversed();
    bool hasReversed();
    void setBase(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getBase();
    bool hasBase();
    NGfc2Surface^ getBasePtr();
    void setCurve(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getCurve();
    bool hasCurve();
    NGfc2Curve3d^ getCurvePtr();
    void setTolerance(NGfc2Double dValue);
    NGfc2Double getTolerance();
    bool hasTolerance();

};
#endif

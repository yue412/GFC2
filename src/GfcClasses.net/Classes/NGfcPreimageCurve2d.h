#ifndef NGFCPREIMAGECURVE2D_H
#define NGFCPREIMAGECURVE2D_H

#include "NGfcCurve2d.h"
#include "GfcClasses\x3\GfcPreimageCurve2d.h"
#include "NGfcIntervald.h"
#include "NGfcSurface.h"
#include "NGfcCurve3d.h"
#include "NTypeDef.h"

public ref class NGfcPreimageCurve2d: public NGfcCurve2d
{
public:
    NGfcPreimageCurve2d();
    NGfcPreimageCurve2d(gfc::engine::CEntity* pEntity, bool bOwner);
    void setRange(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRange();
    bool hasRange();
    void setReversed(NGfcBoolean bValue);
    NGfcBoolean getReversed();
    bool hasReversed();
    void setBase(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getBase();
    bool hasBase();
    void setCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurve();
    bool hasCurve();
    void setTolerance(NGfcDouble dValue);
    NGfcDouble getTolerance();
    bool hasTolerance();

};
#endif

#ifndef NGFC2SINCURVE2D_H
#define NGFC2SINCURVE2D_H

#include "NGfc2Curve2d.h"
#include "GfcClasses\x3\Gfc2SinCurve2d.h"
#include "NGfc2Vector2d.h"
#include "NGfc2Intervald.h"
#include "NTypeDef.h"

public ref class NGfc2SinCurve2d: public NGfc2Curve2d
{
public:
    NGfc2SinCurve2d();
    NGfc2SinCurve2d(gfc::engine::CEntity* pEntity, bool bOwner);
    void setPos(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPos();
    bool hasPos();
    void setDirX(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirX();
    bool hasDirX();
    void setA(NGfc2Double dValue);
    NGfc2Double getA();
    bool hasA();
    void setB(NGfc2Double dValue);
    NGfc2Double getB();
    bool hasB();
    void setRange(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRange();
    bool hasRange();
    void setClockSign(NGfc2Integer nValue);
    NGfc2Integer getClockSign();
    bool hasClockSign();

};
#endif

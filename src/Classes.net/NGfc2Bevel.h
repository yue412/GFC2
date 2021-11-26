#ifndef NGFC2BEVEL_H
#define NGFC2BEVEL_H

#include "NGfc2Surface.h"
#include "GfcClasses\x3\Gfc2Bevel.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Intervald.h"
#include "NGfc2Curve2d.h"
#include "NTypeDef.h"

public ref class NGfc2Bevel: public NGfc2Surface
{
public:
    NGfc2Bevel();
    NGfc2Bevel(void* pEntity, bool bOwner);
    void setCoord(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoord();
    bool hasCoord();
    void setHeight(NGfc2Double dValue);
    NGfc2Double getHeight();
    bool hasHeight();
    void setRangeV(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRangeV();
    bool hasRangeV();
    void setCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurve();
    bool hasCurve();

};
#endif

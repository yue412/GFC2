#ifndef NGFC2OFFSETCURVE2D_H
#define NGFC2OFFSETCURVE2D_H

#include "NGfc2Curve2d.h"
#include "Gfc2OffsetCurve2d.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2OffsetCurve2d: public NGfc2Curve2d
{
public:
    NGfc2OffsetCurve2d();
    NGfc2OffsetCurve2d(void* pEntity, bool bOwner);
    void setOffDist(NGfc2Double dValue);
    NGfc2Double getOffDist();
    bool hasOffDist();
    void setInitCurve(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getInitCurve();
    bool hasInitCurve();
    NGfc2Curve2d^ getInitCurvePtr();

};
#endif

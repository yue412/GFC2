#ifndef NGFC2BEVEL_H
#define NGFC2BEVEL_H

#include "NGfc2Surface.h"
#include "Gfc2Bevel.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Intervald.h"
#include "NGfc2Curve2d.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Bevel: public NGfc2Surface
{
public:
    NGfc2Bevel();
    NGfc2Bevel(void* pEntity, bool bOwner);
    void setCoord(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getCoord();
    bool hasCoord();
    NGfc2Coordinates3d^ getCoordPtr();
    void setHeight(NGfc2Double dValue);
    NGfc2Double getHeight();
    bool hasHeight();
    void setRangeV(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getRangeV();
    bool hasRangeV();
    NGfc2Intervald^ getRangeVPtr();
    void setCurve(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getCurve();
    bool hasCurve();
    NGfc2Curve2d^ getCurvePtr();

};
#endif

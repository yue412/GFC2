#ifndef NGFC2TORUS_H
#define NGFC2TORUS_H

#include "NGfc2Surface.h"
#include "GfcClasses\x3\Gfc2Torus.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Intervald.h"
#include "NGfc2Curve2d.h"
#include "NTypeDef.h"

public ref class NGfc2Torus: public NGfc2Surface
{
public:
    NGfc2Torus();
    NGfc2Torus(gfc::engine::CEntity* pEntity, bool bOwner);
    void setCoord(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoord();
    bool hasCoord();
    void setRadius(NGfc2Double dValue);
    NGfc2Double getRadius();
    bool hasRadius();
    void setClockSign(NGfc2Integer nValue);
    NGfc2Integer getClockSign();
    bool hasClockSign();
    void setRangeV(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRangeV();
    bool hasRangeV();
    void setCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurve();
    bool hasCurve();

};
#endif

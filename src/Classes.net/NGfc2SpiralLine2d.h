#ifndef NGFC2SPIRALLINE2D_H
#define NGFC2SPIRALLINE2D_H

#include "NGfc2Curve2d.h"
#include "GfcClasses\x3\Gfc2SpiralLine2d.h"
#include "NGfc2Coordinates2d.h"
#include "NGfc2Intervald.h"
#include "NTypeDef.h"

public ref class NGfc2SpiralLine2d: public NGfc2Curve2d
{
public:
    NGfc2SpiralLine2d();
    NGfc2SpiralLine2d(void* pEntity, bool bOwner);
    void setCoord(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoord();
    bool hasCoord();
    void setRadius(NGfc2Double dValue);
    NGfc2Double getRadius();
    bool hasRadius();
    void setRange(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRange();
    bool hasRange();
    void setClockSign(NGfc2Integer nValue);
    NGfc2Integer getClockSign();
    bool hasClockSign();
    void setRadiusCoef(NGfc2Double dValue);
    NGfc2Double getRadiusCoef();
    bool hasRadiusCoef();

};
#endif

#ifndef NGFC2SPIRALLINE3D_H
#define NGFC2SPIRALLINE3D_H

#include "NGfc2Curve3d.h"
#include "GfcClasses\x3\Gfc2SpiralLine3d.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Intervald.h"
#include "NTypeDef.h"

public ref class NGfc2SpiralLine3d: public NGfc2Curve3d
{
public:
    NGfc2SpiralLine3d();
    NGfc2SpiralLine3d(void* pEntity, bool bOwner);
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
    void setHeightCoef(NGfc2Double dValue);
    NGfc2Double getHeightCoef();
    bool hasHeightCoef();
    void setRadiusCoef(NGfc2Double dValue);
    NGfc2Double getRadiusCoef();
    bool hasRadiusCoef();

};
#endif

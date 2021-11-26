#ifndef NGFC2HELICOID_H
#define NGFC2HELICOID_H

#include "NGfc2Surface.h"
#include "GfcClasses\x3\Gfc2Helicoid.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Intervald.h"
#include "NGfc2Curve2d.h"
#include "NTypeDef.h"

public ref class NGfc2Helicoid: public NGfc2Surface
{
public:
    NGfc2Helicoid();
    NGfc2Helicoid(gfc::engine::CEntity* pEntity, bool bOwner);
    void setCoord(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoord();
    bool hasCoord();
    void setRadius(NGfc2Double dValue);
    NGfc2Double getRadius();
    bool hasRadius();
    void setRangeV(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRangeV();
    bool hasRangeV();
    void setClockSign(NGfc2Integer nValue);
    NGfc2Integer getClockSign();
    bool hasClockSign();
    void setHeightCoef(NGfc2Double dValue);
    NGfc2Double getHeightCoef();
    bool hasHeightCoef();
    void setRadiusCoef(NGfc2Double dValue);
    NGfc2Double getRadiusCoef();
    bool hasRadiusCoef();
    void setCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurve();
    bool hasCurve();

};
#endif

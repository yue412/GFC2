#ifndef NGFC2HELICOID_H
#define NGFC2HELICOID_H

#include "NGfc2Surface.h"
#include "Gfc2Helicoid.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Intervald.h"
#include "NGfc2Curve2d.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Helicoid: public NGfc2Surface
{
public:
    NGfc2Helicoid();
    NGfc2Helicoid(void* pEntity, bool bOwner);
    void setCoord(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getCoord();
    bool hasCoord();
    NGfc2Coordinates3d^ getCoordPtr();
    void setRadius(NGfc2Double dValue);
    NGfc2Double getRadius();
    bool hasRadius();
    void setRangeV(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getRangeV();
    bool hasRangeV();
    NGfc2Intervald^ getRangeVPtr();
    void setClockSign(NGfc2Integer nValue);
    NGfc2Integer getClockSign();
    bool hasClockSign();
    void setHeightCoef(NGfc2Double dValue);
    NGfc2Double getHeightCoef();
    bool hasHeightCoef();
    void setRadiusCoef(NGfc2Double dValue);
    NGfc2Double getRadiusCoef();
    bool hasRadiusCoef();
    void setCurve(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getCurve();
    bool hasCurve();
    NGfc2Curve2d^ getCurvePtr();

};
#endif

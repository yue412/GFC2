#ifndef NGFC2HELICOID_H
#define NGFC2HELICOID_H

#include "NGfc2Surface.h"
#include "Gfc2Helicoid.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Intervald.h"
#include "NGfc2Curve2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Helicoid: public NGfc2Surface
{
public:
    NGfc2Helicoid();
    NGfc2Helicoid(void* pEntity, bool bOwner);
    void setCoord(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCoord();
    bool hasCoord();
    NGfc2Coordinates3d^ getCoordPtr();
    void setRadius(NGfc2Double dValue);
    NGfc2Double getRadius();
    bool hasRadius();
    void setRangeV(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRangeV();
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
    void setCurve(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCurve();
    bool hasCurve();
    NGfc2Curve2d^ getCurvePtr();

};
#endif

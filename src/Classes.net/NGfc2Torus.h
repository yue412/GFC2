#ifndef NGFC2TORUS_H
#define NGFC2TORUS_H

#include "NGfc2Surface.h"
#include "Gfc2Torus.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Intervald.h"
#include "NGfc2Curve2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Torus: public NGfc2Surface
{
public:
    NGfc2Torus();
    NGfc2Torus(void* pEntity, bool bOwner);
    void setCoord(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCoord();
    bool hasCoord();
    NGfc2Coordinates3d^ getCoordPtr();
    void setRadius(NGfc2Double dValue);
    NGfc2Double getRadius();
    bool hasRadius();
    void setClockSign(NGfc2Integer nValue);
    NGfc2Integer getClockSign();
    bool hasClockSign();
    void setRangeV(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRangeV();
    bool hasRangeV();
    NGfc2Intervald^ getRangeVPtr();
    void setCurve(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCurve();
    bool hasCurve();
    NGfc2Curve2d^ getCurvePtr();

};
#endif

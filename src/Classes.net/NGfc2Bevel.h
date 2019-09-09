#ifndef NGFC2BEVEL_H
#define NGFC2BEVEL_H

#include "NGfc2Surface.h"
#include "Gfc2Bevel.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Intervald.h"
#include "NGfc2Curve2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Bevel: public NGfc2Surface
{
public:
    NGfc2Bevel();
    NGfc2Bevel(void* pEntity, bool bOwner);
    void setCoord(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCoord();
    bool hasCoord();
    NGfc2Coordinates3d^ getCoordPtr();
    void setHeight(NGfc2Double dValue);
    NGfc2Double getHeight();
    bool hasHeight();
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

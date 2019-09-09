#ifndef NGFC2CYLINDER_H
#define NGFC2CYLINDER_H

#include "NGfc2Surface.h"
#include "Gfc2Cylinder.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Intervald.h"
#include "NGfc2Curve2d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Cylinder: public NGfc2Surface
{
public:
    NGfc2Cylinder();
    NGfc2Cylinder(void* pEntity, bool bOwner);
    void setCoord(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCoord();
    bool hasCoord();
    NGfc2Coordinates3d^ getCoordPtr();
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

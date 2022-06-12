#ifndef NGFCEXTRUDEDAREASOLIDSHAPE_H
#define NGFCEXTRUDEDAREASOLIDSHAPE_H

#include "NGfcSweptAreaSolidShape.h"
#include "GfcClasses\x3\GfcExtrudedAreaSolidShape.h"
#include "NGfcVector3d.h"
#include "NTypeDef.h"

public ref class NGfcExtrudedAreaSolidShape: public NGfcSweptAreaSolidShape
{
public:
    NGfcExtrudedAreaSolidShape();
    NGfcExtrudedAreaSolidShape(gfc::engine::CEntity* pEntity, bool bOwner);
    void setExtrudedDirection(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getExtrudedDirection();
    bool hasExtrudedDirection();
    void setLen(NGfcDouble dValue);
    NGfcDouble getLen();
    bool hasLen();

};
#endif

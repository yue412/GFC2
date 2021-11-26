#ifndef NGFC2EXTRUDEDAREASOLIDSHAPE_H
#define NGFC2EXTRUDEDAREASOLIDSHAPE_H

#include "NGfc2SweptAreaSolidShape.h"
#include "GfcClasses\x3\Gfc2ExtrudedAreaSolidShape.h"
#include "NGfc2Vector3d.h"
#include "NTypeDef.h"

public ref class NGfc2ExtrudedAreaSolidShape: public NGfc2SweptAreaSolidShape
{
public:
    NGfc2ExtrudedAreaSolidShape();
    NGfc2ExtrudedAreaSolidShape(gfc::engine::CEntity* pEntity, bool bOwner);
    void setExtrudedDirection(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getExtrudedDirection();
    bool hasExtrudedDirection();
    void setLen(NGfc2Double dValue);
    NGfc2Double getLen();
    bool hasLen();

};
#endif

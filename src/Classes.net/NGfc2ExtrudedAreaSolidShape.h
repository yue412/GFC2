#ifndef NGFC2EXTRUDEDAREASOLIDSHAPE_H
#define NGFC2EXTRUDEDAREASOLIDSHAPE_H

#include "NGfc2SweptAreaSolidShape.h"
#include "Gfc2ExtrudedAreaSolidShape.h"
#include "NGfc2Vector3d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2ExtrudedAreaSolidShape: public NGfc2SweptAreaSolidShape
{
public:
    NGfc2ExtrudedAreaSolidShape();
    NGfc2ExtrudedAreaSolidShape(void* pEntity, bool bOwner);
    void setExtrudedDirection(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getExtrudedDirection();
    bool hasExtrudedDirection();
    NGfc2Vector3d^ getExtrudedDirectionPtr();
    void setLength(NGfc2Double dValue);
    NGfc2Double getLength();
    bool hasLength();

};
#endif

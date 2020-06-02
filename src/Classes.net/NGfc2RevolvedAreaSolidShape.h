#ifndef NGFC2REVOLVEDAREASOLIDSHAPE_H
#define NGFC2REVOLVEDAREASOLIDSHAPE_H

#include "NGfc2SweptAreaSolidShape.h"
#include "Gfc2RevolvedAreaSolidShape.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2RevolvedAreaSolidShape: public NGfc2SweptAreaSolidShape
{
public:
    NGfc2RevolvedAreaSolidShape();
    NGfc2RevolvedAreaSolidShape(void* pEntity, bool bOwner);
    void setAxis(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getAxis();
    bool hasAxis();
    NGfc2Vector2d^ getAxisPtr();
    void setAngle(NGfc2Double dValue);
    NGfc2Double getAngle();
    bool hasAngle();

};
#endif

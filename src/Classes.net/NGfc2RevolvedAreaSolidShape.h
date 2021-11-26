#ifndef NGFC2REVOLVEDAREASOLIDSHAPE_H
#define NGFC2REVOLVEDAREASOLIDSHAPE_H

#include "NGfc2SweptAreaSolidShape.h"
#include "GfcClasses\x3\Gfc2RevolvedAreaSolidShape.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"

public ref class NGfc2RevolvedAreaSolidShape: public NGfc2SweptAreaSolidShape
{
public:
    NGfc2RevolvedAreaSolidShape();
    NGfc2RevolvedAreaSolidShape(gfc::engine::CEntity* pEntity, bool bOwner);
    void setLocation(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getLocation();
    bool hasLocation();
    void setAxis(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getAxis();
    bool hasAxis();
    void setAngle(NGfc2Double dValue);
    NGfc2Double getAngle();
    bool hasAngle();

};
#endif

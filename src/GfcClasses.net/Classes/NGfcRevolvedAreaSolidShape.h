#ifndef NGFCREVOLVEDAREASOLIDSHAPE_H
#define NGFCREVOLVEDAREASOLIDSHAPE_H

#include "NGfcSweptAreaSolidShape.h"
#include "GfcClasses\x3\GfcRevolvedAreaSolidShape.h"
#include "NGfcVector2d.h"
#include "NTypeDef.h"

public ref class NGfcRevolvedAreaSolidShape: public NGfcSweptAreaSolidShape
{
public:
    NGfcRevolvedAreaSolidShape();
    NGfcRevolvedAreaSolidShape(gfc::engine::CEntity* pEntity, bool bOwner);
    void setLocation(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getLocation();
    bool hasLocation();
    void setAxis(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getAxis();
    bool hasAxis();
    void setAngle(NGfcDouble dValue);
    NGfcDouble getAngle();
    bool hasAngle();

};
#endif

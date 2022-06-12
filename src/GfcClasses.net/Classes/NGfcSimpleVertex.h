#ifndef NGFCSIMPLEVERTEX_H
#define NGFCSIMPLEVERTEX_H

#include "NGfcTopology.h"
#include "GfcClasses\x3\GfcSimpleVertex.h"
#include "NGfcVector2d.h"
#include "NTypeDef.h"

public ref class NGfcSimpleVertex: public NGfcTopology
{
public:
    NGfcSimpleVertex();
    NGfcSimpleVertex(gfc::engine::CEntity* pEntity, bool bOwner);
    void setPoint(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPoint();
    bool hasPoint();
    void setRadius(NGfcDouble dValue);
    NGfcDouble getRadius();
    bool hasRadius();
    void setArcType(NGfcArcType nValue);
    NGfcArcType getArcType();
    bool hasArcType();

};
#endif

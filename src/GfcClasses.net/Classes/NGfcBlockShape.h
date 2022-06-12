#ifndef NGFCBLOCKSHAPE_H
#define NGFCBLOCKSHAPE_H

#include "NGfcPrimitiveShape.h"
#include "GfcClasses\x3\GfcBlockShape.h"
#include "NTypeDef.h"

public ref class NGfcBlockShape: public NGfcPrimitiveShape
{
public:
    NGfcBlockShape();
    NGfcBlockShape(gfc::engine::CEntity* pEntity, bool bOwner);
    void setXLength(NGfcDouble dValue);
    NGfcDouble getXLength();
    bool hasXLength();
    void setYLength(NGfcDouble dValue);
    NGfcDouble getYLength();
    bool hasYLength();
    void setZLength(NGfcDouble dValue);
    NGfcDouble getZLength();
    bool hasZLength();

};
#endif

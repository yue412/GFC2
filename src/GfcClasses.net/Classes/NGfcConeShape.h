#ifndef NGFCCONESHAPE_H
#define NGFCCONESHAPE_H

#include "NGfcPrimitiveShape.h"
#include "GfcClasses\x3\GfcConeShape.h"
#include "NTypeDef.h"

public ref class NGfcConeShape: public NGfcPrimitiveShape
{
public:
    NGfcConeShape();
    NGfcConeShape(gfc::engine::CEntity* pEntity, bool bOwner);
    void setHeight(NGfcDouble dValue);
    NGfcDouble getHeight();
    bool hasHeight();
    void setBottomRadius(NGfcDouble dValue);
    NGfcDouble getBottomRadius();
    bool hasBottomRadius();

};
#endif

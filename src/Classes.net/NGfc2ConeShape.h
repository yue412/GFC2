#ifndef NGFC2CONESHAPE_H
#define NGFC2CONESHAPE_H

#include "NGfc2PrimitiveShape.h"
#include "GfcClasses\x3\Gfc2ConeShape.h"
#include "NTypeDef.h"

public ref class NGfc2ConeShape: public NGfc2PrimitiveShape
{
public:
    NGfc2ConeShape();
    NGfc2ConeShape(gfc::engine::CEntity* pEntity, bool bOwner);
    void setHeight(NGfc2Double dValue);
    NGfc2Double getHeight();
    bool hasHeight();
    void setBottomRadius(NGfc2Double dValue);
    NGfc2Double getBottomRadius();
    bool hasBottomRadius();

};
#endif

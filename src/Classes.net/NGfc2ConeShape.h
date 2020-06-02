#ifndef NGFC2CONESHAPE_H
#define NGFC2CONESHAPE_H

#include "NGfc2PrimitiveShape.h"
#include "Gfc2ConeShape.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2ConeShape: public NGfc2PrimitiveShape
{
public:
    NGfc2ConeShape();
    NGfc2ConeShape(void* pEntity, bool bOwner);
    void setHeight(NGfc2Double dValue);
    NGfc2Double getHeight();
    bool hasHeight();
    void setBottomRadius(NGfc2Double dValue);
    NGfc2Double getBottomRadius();
    bool hasBottomRadius();

};
#endif

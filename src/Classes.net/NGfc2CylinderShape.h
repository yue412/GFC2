#ifndef NGFC2CYLINDERSHAPE_H
#define NGFC2CYLINDERSHAPE_H

#include "NGfc2PrimitiveShape.h"
#include "Gfc2CylinderShape.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2CylinderShape: public NGfc2PrimitiveShape
{
public:
    NGfc2CylinderShape();
    NGfc2CylinderShape(void* pEntity, bool bOwner);
    void setHeight(NGfc2Double dValue);
    NGfc2Double getHeight();
    bool hasHeight();
    void setRadius(NGfc2Double dValue);
    NGfc2Double getRadius();
    bool hasRadius();

};
#endif

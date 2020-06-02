#ifndef NGFC2SPHERESHAPE_H
#define NGFC2SPHERESHAPE_H

#include "NGfc2PrimitiveShape.h"
#include "Gfc2SphereShape.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2SphereShape: public NGfc2PrimitiveShape
{
public:
    NGfc2SphereShape();
    NGfc2SphereShape(void* pEntity, bool bOwner);
    void setRadius(NGfc2Double dValue);
    NGfc2Double getRadius();
    bool hasRadius();

};
#endif

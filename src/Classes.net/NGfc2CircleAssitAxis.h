#ifndef NGFC2CIRCLEASSITAXIS_H
#define NGFC2CIRCLEASSITAXIS_H

#include "NGfc2AssitAxis.h"
#include "Gfc2CircleAssitAxis.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2CircleAssitAxis: public NGfc2AssitAxis
{
public:
    NGfc2CircleAssitAxis();
    NGfc2CircleAssitAxis(void* pEntity, bool bOwner);
    void setCenter(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCenter();
    bool hasCenter();
    NGfc2Vector2d^ getCenterPtr();
    void setRadius(NGfc2Double dValue);
    NGfc2Double getRadius();
    bool hasRadius();

};
#endif

#ifndef NGFC2POINTANGLEASSITAXIS_H
#define NGFC2POINTANGLEASSITAXIS_H

#include "NGfc2AssitAxis.h"
#include "Gfc2PointAngleAssitAxis.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2PointAngleAssitAxis: public NGfc2AssitAxis
{
public:
    NGfc2PointAngleAssitAxis();
    NGfc2PointAngleAssitAxis(void* pEntity, bool bOwner);
    void setRefPoint(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRefPoint();
    bool hasRefPoint();
    NGfc2Vector2d^ getRefPointPtr();
    void setAngle(NGfc2Double dValue);
    NGfc2Double getAngle();
    bool hasAngle();

};
#endif

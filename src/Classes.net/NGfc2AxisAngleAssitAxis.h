#ifndef NGFC2AXISANGLEASSITAXIS_H
#define NGFC2AXISANGLEASSITAXIS_H

#include "NGfc2AssitAxis.h"
#include "Gfc2AxisAngleAssitAxis.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2AxisAngleAssitAxis: public NGfc2AssitAxis
{
public:
    NGfc2AxisAngleAssitAxis();
    NGfc2AxisAngleAssitAxis(void* pEntity, bool bOwner);
    void setRefAxisNo(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRefAxisNo();
    bool hasRefAxisNo();
    NGfc2Label^ getRefAxisNoPtr();
    void setRefPoint(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRefPoint();
    bool hasRefPoint();
    NGfc2Vector2d^ getRefPointPtr();
    void setAngle(NGfc2Double dValue);
    NGfc2Double getAngle();
    bool hasAngle();
    void setRefAxisIndex(NGfc2Integer nValue);
    NGfc2Integer getRefAxisIndex();
    bool hasRefAxisIndex();
    void setRefAxisType(NGfc2AxisType nValue);
    NGfc2AxisType getRefAxisType();
    bool hasRefAxisType();

};
#endif

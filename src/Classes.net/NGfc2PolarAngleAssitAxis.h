#ifndef NGFC2POLARANGLEASSITAXIS_H
#define NGFC2POLARANGLEASSITAXIS_H

#include "NGfc2AssitAxis.h"
#include "Gfc2PolarAngleAssitAxis.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2PolarAngleAssitAxis: public NGfc2AssitAxis
{
public:
    NGfc2PolarAngleAssitAxis();
    NGfc2PolarAngleAssitAxis(void* pEntity, bool bOwner);
    void setRefAxisNo(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRefAxisNo();
    bool hasRefAxisNo();
    NGfc2Label^ getRefAxisNoPtr();
    void setAngle(NGfc2Double dValue);
    NGfc2Double getAngle();
    bool hasAngle();
    void setRefAxisIndex(NGfc2Integer nValue);
    NGfc2Integer getRefAxisIndex();
    bool hasRefAxisIndex();

};
#endif

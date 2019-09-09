#ifndef NGFC2PARALLELASSITAXIS_H
#define NGFC2PARALLELASSITAXIS_H

#include "NGfc2AssitAxis.h"
#include "Gfc2ParallelAssitAxis.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2ParallelAssitAxis: public NGfc2AssitAxis
{
public:
    NGfc2ParallelAssitAxis();
    NGfc2ParallelAssitAxis(void* pEntity, bool bOwner);
    void setRefAxisNo(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRefAxisNo();
    bool hasRefAxisNo();
    NGfc2Label^ getRefAxisNoPtr();
    void setOffset(NGfc2Double dValue);
    NGfc2Double getOffset();
    bool hasOffset();
    void setRefAxisIndex(NGfc2Integer nValue);
    NGfc2Integer getRefAxisIndex();
    bool hasRefAxisIndex();
    void setRefAxisType(NGfc2AxisType nValue);
    NGfc2AxisType getRefAxisType();
    bool hasRefAxisType();

};
#endif

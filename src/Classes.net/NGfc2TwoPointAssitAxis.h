#ifndef NGFC2TWOPOINTASSITAXIS_H
#define NGFC2TWOPOINTASSITAXIS_H

#include "NGfc2AssitAxis.h"
#include "Gfc2TwoPointAssitAxis.h"
#include "NGfc2Vector2d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2TwoPointAssitAxis: public NGfc2AssitAxis
{
public:
    NGfc2TwoPointAssitAxis();
    NGfc2TwoPointAssitAxis(void* pEntity, bool bOwner);
    void setStartPt(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getStartPt();
    bool hasStartPt();
    NGfc2Vector2d^ getStartPtPtr();
    void setEndPt(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getEndPt();
    bool hasEndPt();
    NGfc2Vector2d^ getEndPtPtr();

};
#endif

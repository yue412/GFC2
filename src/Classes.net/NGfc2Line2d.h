#ifndef NGFC2LINE2D_H
#define NGFC2LINE2D_H

#include "NGfc2Curve2d.h"
#include "Gfc2Line2d.h"
#include "NGfc2Vector2d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Line2d: public NGfc2Curve2d
{
public:
    NGfc2Line2d();
    NGfc2Line2d(void* pEntity, bool bOwner);
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

#ifndef NGFC2LINE2D_H
#define NGFC2LINE2D_H

#include "NGfc2Curve2d.h"
#include "Gfc2Line2d.h"
#include "NGfc2Vector2d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Line2d: public NGfc2Curve2d
{
public:
    NGfc2Line2d();
    NGfc2Line2d(void* pEntity, bool bOwner);
    void setStartPt(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getStartPt();
    bool hasStartPt();
    NGfc2Vector2d^ getStartPtPtr();
    void setEndPt(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getEndPt();
    bool hasEndPt();
    NGfc2Vector2d^ getEndPtPtr();

};
#endif

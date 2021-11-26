#ifndef NGFC2LINE2D_H
#define NGFC2LINE2D_H

#include "NGfc2Curve2d.h"
#include "GfcClasses\x3\Gfc2Line2d.h"
#include "NGfc2Vector2d.h"

public ref class NGfc2Line2d: public NGfc2Curve2d
{
public:
    NGfc2Line2d();
    NGfc2Line2d(gfc::engine::CEntity* pEntity, bool bOwner);
    void setStartPt(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getStartPt();
    bool hasStartPt();
    void setEndPt(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getEndPt();
    bool hasEndPt();

};
#endif

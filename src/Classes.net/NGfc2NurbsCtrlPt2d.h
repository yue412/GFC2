#ifndef NGFC2NURBSCTRLPT2D_H
#define NGFC2NURBSCTRLPT2D_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2NurbsCtrlPt2d.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"

public ref class NGfc2NurbsCtrlPt2d: public NGfc2Root
{
public:
    NGfc2NurbsCtrlPt2d();
    NGfc2NurbsCtrlPt2d(gfc::engine::CEntity* pEntity, bool bOwner);
    void setPoint(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPoint();
    bool hasPoint();
    void setWeight(NGfc2Double dValue);
    NGfc2Double getWeight();
    bool hasWeight();

};
#endif

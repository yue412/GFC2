#ifndef NGFC2NURBSCTRLPT2D_H
#define NGFC2NURBSCTRLPT2D_H

#include "Gfc2NurbsCtrlPt2d.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2NurbsCtrlPt2d: public glodon::objectbufnet::Entity
{
public:
    NGfc2NurbsCtrlPt2d();
    NGfc2NurbsCtrlPt2d(void* pEntity, bool bOwner);
    void setPoint(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getPoint();
    bool hasPoint();
    NGfc2Vector2d^ getPointPtr();
    void setWeight(NGfc2Double dValue);
    NGfc2Double getWeight();
    bool hasWeight();

};
#endif

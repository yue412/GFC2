#ifndef NGFC2POINTSHAPE2D_H
#define NGFC2POINTSHAPE2D_H

#include "NGfc2Shape2d.h"
#include "Gfc2PointShape2d.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2PointShape2d: public NGfc2Shape2d
{
public:
    NGfc2PointShape2d();
    NGfc2PointShape2d(void* pEntity, bool bOwner);
    void setInsertPt(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getInsertPt();
    bool hasInsertPt();
    NGfc2Vector2d^ getInsertPtPtr();
    void setAngle(NGfc2Double dValue);
    NGfc2Double getAngle();
    bool hasAngle();
    void setMirrorFlag(NGfc2Boolean bValue);
    NGfc2Boolean getMirrorFlag();
    bool hasMirrorFlag();

};
#endif

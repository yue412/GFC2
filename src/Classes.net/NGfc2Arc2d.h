#ifndef NGFC2ARC2D_H
#define NGFC2ARC2D_H

#include "NGfc2Curve2d.h"
#include "Gfc2Arc2d.h"
#include "NGfc2Vector2d.h"
#include "NGfc2Intervald.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Arc2d: public NGfc2Curve2d
{
public:
    NGfc2Arc2d();
    NGfc2Arc2d(void* pEntity, bool bOwner);
    void setCenterPt(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCenterPt();
    bool hasCenterPt();
    NGfc2Vector2d^ getCenterPtPtr();
    void setRadius(NGfc2Double dValue);
    NGfc2Double getRadius();
    bool hasRadius();
    void setRange(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRange();
    bool hasRange();
    NGfc2Intervald^ getRangePtr();
    void setClockSign(NGfc2Integer nValue);
    NGfc2Integer getClockSign();
    bool hasClockSign();

};
#endif

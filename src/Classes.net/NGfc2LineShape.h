#ifndef NGFC2LINESHAPE_H
#define NGFC2LINESHAPE_H

#include "NGfc2CustomLineShape.h"
#include "Gfc2LineShape.h"
#include "NGfc2LineArcInfo.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2LineShape: public NGfc2CustomLineShape
{
public:
    NGfc2LineShape();
    NGfc2LineShape(void* pEntity, bool bOwner);
    void setTilt(NGfc2Double dValue);
    NGfc2Double getTilt();
    bool hasTilt();
    void setStartPtHeight(NGfc2Double dValue);
    NGfc2Double getStartPtHeight();
    bool hasStartPtHeight();
    void setEndPtHeight(NGfc2Double dValue);
    NGfc2Double getEndPtHeight();
    bool hasEndPtHeight();
    void setArcInfo(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getArcInfo();
    bool hasArcInfo();
    NGfc2LineArcInfo^ getArcInfoPtr();
    void setIsSpiralTop(NGfc2Boolean bValue);
    NGfc2Boolean getIsSpiralTop();
    bool hasIsSpiralTop();
    void setIsSpiralBtm(NGfc2Boolean bValue);
    NGfc2Boolean getIsSpiralBtm();
    bool hasIsSpiralBtm();

};
#endif

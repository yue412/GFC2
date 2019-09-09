#ifndef NGFC2CUSTOMLINESHAPE_H
#define NGFC2CUSTOMLINESHAPE_H

#include "NGfc2SolidShape.h"
#include "Gfc2CustomLineShape.h"
#include "NGfc2Curve2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2CustomLineShape: public NGfc2SolidShape
{
public:
    NGfc2CustomLineShape();
    NGfc2CustomLineShape(void* pEntity, bool bOwner);
    void setWidth(NGfc2Double dValue);
    NGfc2Double getWidth();
    bool hasWidth();
    void setLeftWidth(NGfc2Double dValue);
    NGfc2Double getLeftWidth();
    bool hasLeftWidth();
    void setLine(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getLine();
    bool hasLine();
    NGfc2Curve2d^ getLinePtr();
    void setE_S_Elevation(NGfc2Double dValue);
    NGfc2Double getE_S_Elevation();
    bool hasE_S_Elevation();

};
#endif

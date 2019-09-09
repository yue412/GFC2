#ifndef NGFC2CUSTOMPOINTSHAPE_H
#define NGFC2CUSTOMPOINTSHAPE_H

#include "NGfc2SolidShape.h"
#include "Gfc2CustomPointShape.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2CustomPointShape: public NGfc2SolidShape
{
public:
    NGfc2CustomPointShape();
    NGfc2CustomPointShape(void* pEntity, bool bOwner);
    void setInsertPt(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getInsertPt();
    bool hasInsertPt();
    NGfc2Vector2d^ getInsertPtPtr();
    void setBaseInsertPt(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getBaseInsertPt();
    bool hasBaseInsertPt();
    NGfc2Vector2d^ getBaseInsertPtPtr();
    void setAngle(NGfc2Double dValue);
    NGfc2Double getAngle();
    bool hasAngle();
    void setMirrorFlag(NGfc2Boolean bValue);
    NGfc2Boolean getMirrorFlag();
    bool hasMirrorFlag();

};
#endif

#ifndef NGFC2SECTIONLINESHAPE_H
#define NGFC2SECTIONLINESHAPE_H

#include "NGfc2CustomLineShape.h"
#include "Gfc2SectionLineShape.h"
#include "NGfc2Polygon.h"
#include "NGfc2Vector2d.h"
#include "NGfc2BaseLineArcInfo.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2SectionLineShape: public NGfc2CustomLineShape
{
public:
    NGfc2SectionLineShape();
    NGfc2SectionLineShape(void* pEntity, bool bOwner);
    void setPoly(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getPoly();
    bool hasPoly();
    NGfc2Polygon^ getPolyPtr();
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
    void setArcInfo(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getArcInfo();
    bool hasArcInfo();
    NGfc2BaseLineArcInfo^ getArcInfoPtr();
    void setIsSpiral(NGfc2Boolean bValue);
    NGfc2Boolean getIsSpiral();
    bool hasIsSpiral();

};
#endif

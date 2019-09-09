#ifndef NGFC2LINEARCINFO_H
#define NGFC2LINEARCINFO_H

#include "NGfc2BaseLineArcInfo.h"
#include "Gfc2LineArcInfo.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2LineArcInfo: public NGfc2BaseLineArcInfo
{
public:
    NGfc2LineArcInfo();
    NGfc2LineArcInfo(void* pEntity, bool bOwner);
    void setBasePoint(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getBasePoint();
    bool hasBasePoint();
    NGfc2Vector2d^ getBasePointPtr();
    void setArchHeight(NGfc2Double dValue);
    NGfc2Double getArchHeight();
    bool hasArchHeight();
    void setHalfChordLength(NGfc2Double dValue);
    NGfc2Double getHalfChordLength();
    bool hasHalfChordLength();
    void setRadius(NGfc2Double dValue);
    NGfc2Double getRadius();
    bool hasRadius();
    void setDefineByRadius(NGfc2Boolean bValue);
    NGfc2Boolean getDefineByRadius();
    bool hasDefineByRadius();

};
#endif

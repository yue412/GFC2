#ifndef NGFC2FLOOR_H
#define NGFC2FLOOR_H

#include "NGfc2SpatialStructureElement.h"
#include "Gfc2Floor.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Floor: public NGfc2SpatialStructureElement
{
public:
    NGfc2Floor();
    NGfc2Floor(void* pEntity, bool bOwner);
    void setHeight(NGfc2Double dValue);
    NGfc2Double getHeight();
    bool hasHeight();
    void setStdFloorCount(NGfc2Integer nValue);
    NGfc2Integer getStdFloorCount();
    bool hasStdFloorCount();
    void setStructuralElevation(NGfc2Double dValue);
    NGfc2Double getStructuralElevation();
    bool hasStructuralElevation();
    void setStartFloorNo(NGfc2Integer nValue);
    NGfc2Integer getStartFloorNo();
    bool hasStartFloorNo();
    void setRemark(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRemark();
    bool hasRemark();
    NGfc2Text^ getRemarkPtr();

};
#endif

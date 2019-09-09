#ifndef NGFC2STEELTOTAL_H
#define NGFC2STEELTOTAL_H

#include "Gfc2SteelTotal.h"
#include "NGfc2String.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2SteelTotal: public glodon::objectbufnet::Entity
{
public:
    NGfc2SteelTotal();
    NGfc2SteelTotal(void* pEntity, bool bOwner);
    void setCompType(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCompType();
    bool hasCompType();
    NGfc2String^ getCompTypePtr();
    void setLevel(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getLevel();
    bool hasLevel();
    NGfc2String^ getLevelPtr();
    void setDia(NGfc2Integer nValue);
    NGfc2Integer getDia();
    bool hasDia();
    void setWeight(NGfc2Double dValue);
    NGfc2Double getWeight();
    bool hasWeight();
    void setUnit(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getUnit();
    bool hasUnit();
    NGfc2String^ getUnitPtr();

};
#endif

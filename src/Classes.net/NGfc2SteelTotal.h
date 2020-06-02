#ifndef NGFC2STEELTOTAL_H
#define NGFC2STEELTOTAL_H

#include "Gfc2SteelTotal.h"
#include "NGfc2String.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2SteelTotal: public glodon::objectbufnet::Entity
{
public:
    NGfc2SteelTotal();
    NGfc2SteelTotal(void* pEntity, bool bOwner);
    void setCompType(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getCompType();
    bool hasCompType();
    NGfc2String^ getCompTypePtr();
    void setLevel(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getLevel();
    bool hasLevel();
    NGfc2String^ getLevelPtr();
    void setDia(NGfc2Integer nValue);
    NGfc2Integer getDia();
    bool hasDia();
    void setWeight(NGfc2Double dValue);
    NGfc2Double getWeight();
    bool hasWeight();
    void setUnit(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getUnit();
    bool hasUnit();
    NGfc2String^ getUnitPtr();

};
#endif

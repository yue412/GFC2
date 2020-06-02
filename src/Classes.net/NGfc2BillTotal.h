#ifndef NGFC2BILLTOTAL_H
#define NGFC2BILLTOTAL_H

#include "Gfc2BillTotal.h"
#include "NGfc2String.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2BillTotal: public glodon::objectbufnet::Entity
{
public:
    NGfc2BillTotal();
    NGfc2BillTotal(void* pEntity, bool bOwner);
    void setCode(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getCode();
    bool hasCode();
    NGfc2String^ getCodePtr();
    void setName(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getName();
    bool hasName();
    NGfc2String^ getNamePtr();
    void setAttr(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getAttr();
    bool hasAttr();
    NGfc2String^ getAttrPtr();
    void setQuantityType(NGfc2Integer nValue);
    NGfc2Integer getQuantityType();
    bool hasQuantityType();
    void setUnit(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getUnit();
    bool hasUnit();
    NGfc2String^ getUnitPtr();
    void setQuantity(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getQuantity();
    bool hasQuantity();
    NGfc2String^ getQuantityPtr();
    void setMemo(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getMemo();
    bool hasMemo();
    NGfc2String^ getMemoPtr();

};
#endif

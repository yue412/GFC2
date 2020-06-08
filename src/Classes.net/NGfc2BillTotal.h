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
    void setCode(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCode();
    bool hasCode();
    NGfc2String^ getCodePtr();
    void setName(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getName();
    bool hasName();
    NGfc2String^ getNamePtr();
    void setAttr(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getAttr();
    bool hasAttr();
    NGfc2String^ getAttrPtr();
    void setQuantityType(NGfc2Integer nValue);
    NGfc2Integer getQuantityType();
    bool hasQuantityType();
    void setUnit(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getUnit();
    bool hasUnit();
    NGfc2String^ getUnitPtr();
    void setQuantity(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getQuantity();
    bool hasQuantity();
    NGfc2String^ getQuantityPtr();
    void setMemo(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMemo();
    bool hasMemo();
    NGfc2String^ getMemoPtr();

};
#endif

#ifndef NGFC2BILLTOTAL_H
#define NGFC2BILLTOTAL_H

#include "Gfc2BillTotal.h"
#include "NGfc2String.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2BillTotal: public glodon::objectbufnet::Entity
{
public:
    NGfc2BillTotal();
    NGfc2BillTotal(void* pEntity, bool bOwner);
    void setCode(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCode();
    bool hasCode();
    NGfc2String^ getCodePtr();
    void setName(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getName();
    bool hasName();
    NGfc2String^ getNamePtr();
    void setAttr(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getAttr();
    bool hasAttr();
    NGfc2String^ getAttrPtr();
    void setQuantityType(NGfc2Integer nValue);
    NGfc2Integer getQuantityType();
    bool hasQuantityType();
    void setUnit(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getUnit();
    bool hasUnit();
    NGfc2String^ getUnitPtr();
    void setQuantity(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getQuantity();
    bool hasQuantity();
    NGfc2String^ getQuantityPtr();
    void setMemo(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getMemo();
    bool hasMemo();
    NGfc2String^ getMemoPtr();

};
#endif

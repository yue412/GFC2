#ifndef NGFC2QUOTATOTAL_H
#define NGFC2QUOTATOTAL_H

#include "Gfc2QuotaTotal.h"
#include "NGfc2String.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2QuotaTotal: public glodon::objectbufnet::Entity
{
public:
    NGfc2QuotaTotal();
    NGfc2QuotaTotal(void* pEntity, bool bOwner);
    void setCode(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCode();
    bool hasCode();
    NGfc2String^ getCodePtr();
    void setSubCode(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getSubCode();
    bool hasSubCode();
    NGfc2String^ getSubCodePtr();
    void setName(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getName();
    bool hasName();
    NGfc2String^ getNamePtr();
    void setContent(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getContent();
    bool hasContent();
    NGfc2String^ getContentPtr();
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

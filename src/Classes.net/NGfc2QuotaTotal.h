#ifndef NGFC2QUOTATOTAL_H
#define NGFC2QUOTATOTAL_H

#include "Gfc2QuotaTotal.h"
#include "NGfc2String.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2QuotaTotal: public glodon::objectbufnet::Entity
{
public:
    NGfc2QuotaTotal();
    NGfc2QuotaTotal(void* pEntity, bool bOwner);
    void setCode(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getCode();
    bool hasCode();
    NGfc2String^ getCodePtr();
    void setSubCode(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getSubCode();
    bool hasSubCode();
    NGfc2String^ getSubCodePtr();
    void setName(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getName();
    bool hasName();
    NGfc2String^ getNamePtr();
    void setContent(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getContent();
    bool hasContent();
    NGfc2String^ getContentPtr();
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

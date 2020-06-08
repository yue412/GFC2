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
    void setCode(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCode();
    bool hasCode();
    NGfc2String^ getCodePtr();
    void setSubCode(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSubCode();
    bool hasSubCode();
    NGfc2String^ getSubCodePtr();
    void setName(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getName();
    bool hasName();
    NGfc2String^ getNamePtr();
    void setContent(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getContent();
    bool hasContent();
    NGfc2String^ getContentPtr();
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

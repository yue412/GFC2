#ifndef NGFC2QUOTADETAIL_H
#define NGFC2QUOTADETAIL_H

#include "Gfc2QuotaDetail.h"
#include "NGfc2String.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2QuotaDetail: public glodon::objectbufnet::Entity
{
public:
    NGfc2QuotaDetail();
    NGfc2QuotaDetail(void* pEntity, bool bOwner);
    void setFloorNum(NGfc2Integer nValue);
    NGfc2Integer getFloorNum();
    bool hasFloorNum();
    void setEntityID(NGfc2Integer nValue);
    NGfc2Integer getEntityID();
    bool hasEntityID();
    void setUnit(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getUnit();
    bool hasUnit();
    NGfc2String^ getUnitPtr();
    void setExpress(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getExpress();
    bool hasExpress();
    NGfc2String^ getExpressPtr();
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

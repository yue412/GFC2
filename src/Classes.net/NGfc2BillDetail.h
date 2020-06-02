#ifndef NGFC2BILLDETAIL_H
#define NGFC2BILLDETAIL_H

#include "Gfc2BillDetail.h"
#include "NGfc2String.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2BillDetail: public glodon::objectbufnet::Entity
{
public:
    NGfc2BillDetail();
    NGfc2BillDetail(void* pEntity, bool bOwner);
    void setFloorNum(NGfc2Integer nValue);
    NGfc2Integer getFloorNum();
    bool hasFloorNum();
    void setEntityID(NGfc2Integer nValue);
    NGfc2Integer getEntityID();
    bool hasEntityID();
    void setUnit(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getUnit();
    bool hasUnit();
    NGfc2String^ getUnitPtr();
    void setExpress(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getExpress();
    bool hasExpress();
    NGfc2String^ getExpressPtr();
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

#ifndef NGFC2QUOTADETAIL_H
#define NGFC2QUOTADETAIL_H

#include "Gfc2QuotaDetail.h"
#include "NGfc2String.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

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
    void setUnit(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getUnit();
    bool hasUnit();
    NGfc2String^ getUnitPtr();
    void setExpress(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getExpress();
    bool hasExpress();
    NGfc2String^ getExpressPtr();
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

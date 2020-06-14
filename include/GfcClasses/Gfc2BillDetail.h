#ifndef GFC2BILLDETAIL_H
#define GFC2BILLDETAIL_H

#include "GfcClasses.h"
#include "Gfc2String.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2BillDetail: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2BillDetail, gfc::engine::CEntity)
public:
    Gfc2BillDetail();
    Gfc2BillDetail(bool bSetSchema);
    void setFloorNum(const Gfc2Integer& nValue);
    Gfc2Integer getFloorNum() const;
    bool hasFloorNum() const;
    void setEntityID(const Gfc2Integer& nValue);
    Gfc2Integer getEntityID() const;
    bool hasEntityID() const;
    void setUnit(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getUnit() const;
    bool hasUnit() const;
    gfc::engine::CEntityWrapPtr<Gfc2String> getUnitPtr();
    void setExpress(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getExpress() const;
    bool hasExpress() const;
    gfc::engine::CEntityWrapPtr<Gfc2String> getExpressPtr();
    void setQuantity(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getQuantity() const;
    bool hasQuantity() const;
    gfc::engine::CEntityWrapPtr<Gfc2String> getQuantityPtr();
    void setMemo(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getMemo() const;
    bool hasMemo() const;
    gfc::engine::CEntityWrapPtr<Gfc2String> getMemoPtr();

};
#endif

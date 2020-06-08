#ifndef GFC2QUOTADETAIL_H
#define GFC2QUOTADETAIL_H

#include "GfcClasses.h"
#include "Gfc2String.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2QuotaDetail: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2QuotaDetail, gfc::engine::CEntity)
public:
    Gfc2QuotaDetail();
    Gfc2QuotaDetail(bool bSetSchema);
    void setFloorNum(const Gfc2Integer& nValue);
    Gfc2Integer getFloorNum() const;
    bool hasFloorNum() const;
    void setEntityID(const Gfc2Integer& nValue);
    Gfc2Integer getEntityID() const;
    bool hasEntityID() const;
    void setUnit(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getUnit() const;
    bool hasUnit() const;
    std::shared_ptr<Gfc2String> getUnitPtr();
    void setExpress(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getExpress() const;
    bool hasExpress() const;
    std::shared_ptr<Gfc2String> getExpressPtr();
    void setQuantity(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getQuantity() const;
    bool hasQuantity() const;
    std::shared_ptr<Gfc2String> getQuantityPtr();
    void setMemo(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getMemo() const;
    bool hasMemo() const;
    std::shared_ptr<Gfc2String> getMemoPtr();

};
#endif

#ifndef GFC2QUOTATOTAL_H
#define GFC2QUOTATOTAL_H

#include "GfcClasses.h"
#include "Gfc2String.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2QuotaTotal: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2QuotaTotal, gfc::engine::CEntity)
public:
    Gfc2QuotaTotal();
    Gfc2QuotaTotal(bool bSetSchema);
    void setCode(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCode() const;
    bool hasCode() const;
    std::shared_ptr<Gfc2String> getCodePtr();
    void setSubCode(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSubCode() const;
    bool hasSubCode() const;
    std::shared_ptr<Gfc2String> getSubCodePtr();
    void setName(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getName() const;
    bool hasName() const;
    std::shared_ptr<Gfc2String> getNamePtr();
    void setContent(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getContent() const;
    bool hasContent() const;
    std::shared_ptr<Gfc2String> getContentPtr();
    void setUnit(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getUnit() const;
    bool hasUnit() const;
    std::shared_ptr<Gfc2String> getUnitPtr();
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

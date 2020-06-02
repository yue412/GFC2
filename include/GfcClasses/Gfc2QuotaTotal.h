#ifndef GFC2QUOTATOTAL_H
#define GFC2QUOTATOTAL_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2String.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2QuotaTotal: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2QuotaTotal,gfc2::engine::EntityFactory)
public:
    Gfc2QuotaTotal();
    Gfc2QuotaTotal(bool bSetSchema);
    void setCode(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getCode() const;
    bool hasCode() const;
    std::shared_ptr<Gfc2String> getCodePtr();
    void setSubCode(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getSubCode() const;
    bool hasSubCode() const;
    std::shared_ptr<Gfc2String> getSubCodePtr();
    void setName(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getName() const;
    bool hasName() const;
    std::shared_ptr<Gfc2String> getNamePtr();
    void setContent(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getContent() const;
    bool hasContent() const;
    std::shared_ptr<Gfc2String> getContentPtr();
    void setUnit(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getUnit() const;
    bool hasUnit() const;
    std::shared_ptr<Gfc2String> getUnitPtr();
    void setQuantity(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getQuantity() const;
    bool hasQuantity() const;
    std::shared_ptr<Gfc2String> getQuantityPtr();
    void setMemo(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getMemo() const;
    bool hasMemo() const;
    std::shared_ptr<Gfc2String> getMemoPtr();

};
#endif

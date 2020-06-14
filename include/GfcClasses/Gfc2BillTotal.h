#ifndef GFC2BILLTOTAL_H
#define GFC2BILLTOTAL_H

#include "GfcClasses.h"
#include "Gfc2String.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2BillTotal: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2BillTotal, gfc::engine::CEntity)
public:
    Gfc2BillTotal();
    Gfc2BillTotal(bool bSetSchema);
    void setCode(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCode() const;
    bool hasCode() const;
    gfc::engine::CEntityWrapPtr<Gfc2String> getCodePtr();
    void setName(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getName() const;
    bool hasName() const;
    gfc::engine::CEntityWrapPtr<Gfc2String> getNamePtr();
    void setAttr(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getAttr() const;
    bool hasAttr() const;
    gfc::engine::CEntityWrapPtr<Gfc2String> getAttrPtr();
    void setQuantityType(const Gfc2Integer& nValue);
    Gfc2Integer getQuantityType() const;
    bool hasQuantityType() const;
    void setUnit(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getUnit() const;
    bool hasUnit() const;
    gfc::engine::CEntityWrapPtr<Gfc2String> getUnitPtr();
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

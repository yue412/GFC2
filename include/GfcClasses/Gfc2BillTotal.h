#ifndef GFC2BILLTOTAL_H
#define GFC2BILLTOTAL_H

#include "GfcClasses.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2BillTotal: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2BillTotal, gfc::engine::CEntity)
public:
    Gfc2BillTotal();
    Gfc2BillTotal(bool bSetSchema);
    void setCode(const Gfc2String& sValue);
    Gfc2String getCode() const;
    bool hasCode() const;
    void setName(const Gfc2String& sValue);
    Gfc2String getName() const;
    bool hasName() const;
    void setAttr(const Gfc2String& sValue);
    Gfc2String getAttr() const;
    bool hasAttr() const;
    void setQuantityType(const Gfc2Integer& nValue);
    Gfc2Integer getQuantityType() const;
    bool hasQuantityType() const;
    void setUnit(const Gfc2String& sValue);
    Gfc2String getUnit() const;
    bool hasUnit() const;
    void setQuantity(const Gfc2String& sValue);
    Gfc2String getQuantity() const;
    bool hasQuantity() const;
    void setMemo(const Gfc2String& sValue);
    Gfc2String getMemo() const;
    bool hasMemo() const;

};

GFCCLASSES_NAMESPACE_END

#endif

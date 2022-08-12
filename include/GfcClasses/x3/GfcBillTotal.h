#ifndef GFCBILLTOTAL_H
#define GFCBILLTOTAL_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRoot.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcBillTotal: public GfcRoot
{
GFCENGINE_DEC_OBJECT(GfcBillTotal, gfc::engine::CEntity)
public:
    GfcBillTotal();
    GfcBillTotal(bool bSetSchema);
    void setCode(const GfcString& sValue);
    GfcString getCode() const;
    bool hasCode() const;
    void setName(const GfcString& sValue);
    GfcString getName() const;
    bool hasName() const;
    void setAttr(const GfcString& sValue);
    GfcString getAttr() const;
    bool hasAttr() const;
    void setQuantityType(const GfcInteger& nValue);
    GfcInteger getQuantityType() const;
    bool hasQuantityType() const;
    void setUnit(const GfcString& sValue);
    GfcString getUnit() const;
    bool hasUnit() const;
    void setQuantity(const GfcString& sValue);
    GfcString getQuantity() const;
    bool hasQuantity() const;
    void setMemo(const GfcString& sValue);
    GfcString getMemo() const;
    bool hasMemo() const;

};

GFCCLASSES_NAMESPACE_END

#endif

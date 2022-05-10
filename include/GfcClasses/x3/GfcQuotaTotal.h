#ifndef GFCQUOTATOTAL_H
#define GFCQUOTATOTAL_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcQuotaTotal: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcQuotaTotal, gfc::engine::CEntity)
public:
    GfcQuotaTotal();
    GfcQuotaTotal(bool bSetSchema);
    void setCode(const GfcString& sValue);
    GfcString getCode() const;
    bool hasCode() const;
    void setSubCode(const GfcString& sValue);
    GfcString getSubCode() const;
    bool hasSubCode() const;
    void setName(const GfcString& sValue);
    GfcString getName() const;
    bool hasName() const;
    void setContent(const GfcString& sValue);
    GfcString getContent() const;
    bool hasContent() const;
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

#ifndef GFC2QUOTATOTAL_H
#define GFC2QUOTATOTAL_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Root.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2QuotaTotal: public Gfc2Root
{
GFCENGINE_DEC_OBJECT(Gfc2QuotaTotal, gfc::engine::CEntity)
public:
    Gfc2QuotaTotal();
    Gfc2QuotaTotal(bool bSetSchema);
    void setCode(const Gfc2String& sValue);
    Gfc2String getCode() const;
    bool hasCode() const;
    void setSubCode(const Gfc2String& sValue);
    Gfc2String getSubCode() const;
    bool hasSubCode() const;
    void setName(const Gfc2String& sValue);
    Gfc2String getName() const;
    bool hasName() const;
    void setContent(const Gfc2String& sValue);
    Gfc2String getContent() const;
    bool hasContent() const;
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

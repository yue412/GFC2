#ifndef GFC2QUOTADETAIL_H
#define GFC2QUOTADETAIL_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Root.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2QuotaDetail: public Gfc2Root
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
    void setUnit(const Gfc2String& sValue);
    Gfc2String getUnit() const;
    bool hasUnit() const;
    void setExpress(const Gfc2String& sValue);
    Gfc2String getExpress() const;
    bool hasExpress() const;
    void setQuantity(const Gfc2String& sValue);
    Gfc2String getQuantity() const;
    bool hasQuantity() const;
    void setMemo(const Gfc2String& sValue);
    Gfc2String getMemo() const;
    bool hasMemo() const;

};

GFCCLASSES_NAMESPACE_END

#endif

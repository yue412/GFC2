#ifndef GFCBILLDETAIL_H
#define GFCBILLDETAIL_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcBillDetail: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcBillDetail, gfc::engine::CEntity)
public:
    GfcBillDetail();
    GfcBillDetail(bool bSetSchema);
    void setFloorNum(const GfcInteger& nValue);
    GfcInteger getFloorNum() const;
    bool hasFloorNum() const;
    void setEntityID(const GfcInteger& nValue);
    GfcInteger getEntityID() const;
    bool hasEntityID() const;
    void setUnit(const GfcString& sValue);
    GfcString getUnit() const;
    bool hasUnit() const;
    void setExpress(const GfcString& sValue);
    GfcString getExpress() const;
    bool hasExpress() const;
    void setQuantity(const GfcString& sValue);
    GfcString getQuantity() const;
    bool hasQuantity() const;
    void setMemo(const GfcString& sValue);
    GfcString getMemo() const;
    bool hasMemo() const;

};

GFCCLASSES_NAMESPACE_END

#endif

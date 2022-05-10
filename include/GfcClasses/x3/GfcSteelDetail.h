#ifndef GFCSTEELDETAIL_H
#define GFCSTEELDETAIL_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSteelDetail: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcSteelDetail, gfc::engine::CEntity)
public:
    GfcSteelDetail();
    GfcSteelDetail(bool bSetSchema);
    void setEntityID(const GfcInteger& nValue);
    GfcInteger getEntityID() const;
    bool hasEntityID() const;
    void setName(const GfcString& sValue);
    GfcString getName() const;
    bool hasName() const;
    void setDesc(const GfcString& sValue);
    GfcString getDesc() const;
    bool hasDesc() const;
    void setLevel(const GfcString& sValue);
    GfcString getLevel() const;
    bool hasLevel() const;
    void setDia(const GfcInteger& nValue);
    GfcInteger getDia() const;
    bool hasDia() const;
    void setNum(const GfcInteger& nValue);
    GfcInteger getNum() const;
    bool hasNum() const;
    void setBarLength(const GfcInteger& nValue);
    GfcInteger getBarLength() const;
    bool hasBarLength() const;
    void setSingleWeight(const GfcDouble& dValue);
    GfcDouble getSingleWeight() const;
    bool hasSingleWeight() const;
    void setTotalWeight(const GfcDouble& dValue);
    GfcDouble getTotalWeight() const;
    bool hasTotalWeight() const;
    void setTieinNum(const GfcInteger& nValue);
    GfcInteger getTieinNum() const;
    bool hasTieinNum() const;
    void setTieinType(const GfcString& sValue);
    GfcString getTieinType() const;
    bool hasTieinType() const;

};

GFCCLASSES_NAMESPACE_END

#endif

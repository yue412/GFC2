#ifndef GFC2STEELDETAIL_H
#define GFC2STEELDETAIL_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Root.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2SteelDetail: public Gfc2Root
{
GFCENGINE_DEC_OBJECT(Gfc2SteelDetail, gfc::engine::CEntity)
public:
    Gfc2SteelDetail();
    Gfc2SteelDetail(bool bSetSchema);
    void setEntityID(const Gfc2Integer& nValue);
    Gfc2Integer getEntityID() const;
    bool hasEntityID() const;
    void setName(const Gfc2String& sValue);
    Gfc2String getName() const;
    bool hasName() const;
    void setDesc(const Gfc2String& sValue);
    Gfc2String getDesc() const;
    bool hasDesc() const;
    void setLevel(const Gfc2String& sValue);
    Gfc2String getLevel() const;
    bool hasLevel() const;
    void setDia(const Gfc2Integer& nValue);
    Gfc2Integer getDia() const;
    bool hasDia() const;
    void setNum(const Gfc2Integer& nValue);
    Gfc2Integer getNum() const;
    bool hasNum() const;
    void setBarLength(const Gfc2Integer& nValue);
    Gfc2Integer getBarLength() const;
    bool hasBarLength() const;
    void setSingleWeight(const Gfc2Double& dValue);
    Gfc2Double getSingleWeight() const;
    bool hasSingleWeight() const;
    void setTotalWeight(const Gfc2Double& dValue);
    Gfc2Double getTotalWeight() const;
    bool hasTotalWeight() const;
    void setTieinNum(const Gfc2Integer& nValue);
    Gfc2Integer getTieinNum() const;
    bool hasTieinNum() const;
    void setTieinType(const Gfc2String& sValue);
    Gfc2String getTieinType() const;
    bool hasTieinType() const;

};

GFCCLASSES_NAMESPACE_END

#endif

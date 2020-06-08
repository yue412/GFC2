#ifndef GFC2STEELDETAIL_H
#define GFC2STEELDETAIL_H

#include "GfcClasses.h"
#include "Gfc2String.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SteelDetail: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2SteelDetail, gfc::engine::CEntity)
public:
    Gfc2SteelDetail();
    Gfc2SteelDetail(bool bSetSchema);
    void setEntityID(const Gfc2Integer& nValue);
    Gfc2Integer getEntityID() const;
    bool hasEntityID() const;
    void setName(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getName() const;
    bool hasName() const;
    std::shared_ptr<Gfc2String> getNamePtr();
    void setDesc(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDesc() const;
    bool hasDesc() const;
    std::shared_ptr<Gfc2String> getDescPtr();
    void setLevel(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLevel() const;
    bool hasLevel() const;
    std::shared_ptr<Gfc2String> getLevelPtr();
    void setDia(const Gfc2Integer& nValue);
    Gfc2Integer getDia() const;
    bool hasDia() const;
    void setNum(const Gfc2Integer& nValue);
    Gfc2Integer getNum() const;
    bool hasNum() const;
    void setLength(const Gfc2Integer& nValue);
    Gfc2Integer getLength() const;
    bool hasLength() const;
    void setSingleWeight(const Gfc2Double& dValue);
    Gfc2Double getSingleWeight() const;
    bool hasSingleWeight() const;
    void setTotalWeight(const Gfc2Double& dValue);
    Gfc2Double getTotalWeight() const;
    bool hasTotalWeight() const;
    void setTieinNum(const Gfc2Integer& nValue);
    Gfc2Integer getTieinNum() const;
    bool hasTieinNum() const;
    void setTieinType(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getTieinType() const;
    bool hasTieinType() const;
    std::shared_ptr<Gfc2String> getTieinTypePtr();

};
#endif

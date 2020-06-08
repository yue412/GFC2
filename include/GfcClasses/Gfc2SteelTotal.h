#ifndef GFC2STEELTOTAL_H
#define GFC2STEELTOTAL_H

#include "GfcClasses.h"
#include "Gfc2String.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SteelTotal: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2SteelTotal, gfc::engine::CEntity)
public:
    Gfc2SteelTotal();
    Gfc2SteelTotal(bool bSetSchema);
    void setCompType(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCompType() const;
    bool hasCompType() const;
    std::shared_ptr<Gfc2String> getCompTypePtr();
    void setLevel(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLevel() const;
    bool hasLevel() const;
    std::shared_ptr<Gfc2String> getLevelPtr();
    void setDia(const Gfc2Integer& nValue);
    Gfc2Integer getDia() const;
    bool hasDia() const;
    void setWeight(const Gfc2Double& dValue);
    Gfc2Double getWeight() const;
    bool hasWeight() const;
    void setUnit(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getUnit() const;
    bool hasUnit() const;
    std::shared_ptr<Gfc2String> getUnitPtr();

};
#endif
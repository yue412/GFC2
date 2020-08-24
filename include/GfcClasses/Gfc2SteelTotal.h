#ifndef GFC2STEELTOTAL_H
#define GFC2STEELTOTAL_H

#include "GfcClasses.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SteelTotal: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2SteelTotal, gfc::engine::CEntity)
public:
    Gfc2SteelTotal();
    Gfc2SteelTotal(bool bSetSchema);
    void setCompType(const Gfc2String& sValue);
    Gfc2String getCompType() const;
    bool hasCompType() const;
    void setLevel(const Gfc2String& sValue);
    Gfc2String getLevel() const;
    bool hasLevel() const;
    void setDia(const Gfc2Integer& nValue);
    Gfc2Integer getDia() const;
    bool hasDia() const;
    void setWeight(const Gfc2Double& dValue);
    Gfc2Double getWeight() const;
    bool hasWeight() const;
    void setUnit(const Gfc2String& sValue);
    Gfc2String getUnit() const;
    bool hasUnit() const;

};
#endif

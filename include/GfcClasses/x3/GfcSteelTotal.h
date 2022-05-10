#ifndef GFCSTEELTOTAL_H
#define GFCSTEELTOTAL_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSteelTotal: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcSteelTotal, gfc::engine::CEntity)
public:
    GfcSteelTotal();
    GfcSteelTotal(bool bSetSchema);
    void setCompType(const GfcString& sValue);
    GfcString getCompType() const;
    bool hasCompType() const;
    void setLevel(const GfcString& sValue);
    GfcString getLevel() const;
    bool hasLevel() const;
    void setDia(const GfcInteger& nValue);
    GfcInteger getDia() const;
    bool hasDia() const;
    void setWeight(const GfcDouble& dValue);
    GfcDouble getWeight() const;
    bool hasWeight() const;
    void setUnit(const GfcString& sValue);
    GfcString getUnit() const;
    bool hasUnit() const;

};

GFCCLASSES_NAMESPACE_END

#endif

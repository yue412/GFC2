#ifndef GFCRULEDSURFACE_H
#define GFCRULEDSURFACE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSurface.h"
#include "GfcClasses/x3/GfcIntervald.h"
#include "GfcClasses/x3/GfcCurve3d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRuledSurface: public GfcSurface
{
GFCENGINE_DEC_OBJECT(GfcRuledSurface, gfc::engine::CEntity)
public:
    GfcRuledSurface();
    GfcRuledSurface(bool bSetSchema);
    void setApexIndex(const GfcInteger& nValue);
    GfcInteger getApexIndex() const;
    bool hasApexIndex() const;
    void setRangeV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeV() const;
    bool hasRangeV() const;
    std::shared_ptr<GfcIntervald> getRangeVPtr();
    void setRangeU(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeU() const;
    bool hasRangeU() const;
    std::shared_ptr<GfcIntervald> getRangeUPtr();
    void setDirectrix1(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirectrix1() const;
    bool hasDirectrix1() const;
    std::shared_ptr<GfcCurve3d> getDirectrix1Ptr();
    void setDirectrix2(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirectrix2() const;
    bool hasDirectrix2() const;
    std::shared_ptr<GfcCurve3d> getDirectrix2Ptr();

};

GFCCLASSES_NAMESPACE_END

#endif

#ifndef GFC2RULEDSURFACE_H
#define GFC2RULEDSURFACE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Surface.h"
#include "GfcClasses/x3/Gfc2Intervald.h"
#include "GfcClasses/x3/Gfc2Curve3d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RuledSurface: public Gfc2Surface
{
GFCENGINE_DEC_OBJECT(Gfc2RuledSurface, gfc::engine::CEntity)
public:
    Gfc2RuledSurface();
    Gfc2RuledSurface(bool bSetSchema);
    void setApexIndex(const Gfc2Integer& nValue);
    Gfc2Integer getApexIndex() const;
    bool hasApexIndex() const;
    void setRangeV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeV() const;
    bool hasRangeV() const;
    gfc::engine::CEntityWrapPtr<Gfc2Intervald> getRangeVPtr();
    void setRangeU(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeU() const;
    bool hasRangeU() const;
    gfc::engine::CEntityWrapPtr<Gfc2Intervald> getRangeUPtr();
    void setDirectrix1(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirectrix1() const;
    bool hasDirectrix1() const;
    gfc::engine::CEntityWrapPtr<Gfc2Curve3d> getDirectrix1Ptr();
    void setDirectrix2(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirectrix2() const;
    bool hasDirectrix2() const;
    gfc::engine::CEntityWrapPtr<Gfc2Curve3d> getDirectrix2Ptr();

};

GFCCLASSES_NAMESPACE_END

#endif

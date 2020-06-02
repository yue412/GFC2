#ifndef GFC2RULEDSURFACE_H
#define GFC2RULEDSURFACE_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Surface.h"
#include "Gfc2Intervald.h"
#include "Gfc2Curve3d.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RuledSurface: public Gfc2Surface
{
GFCENGINE_DEC_OBJECT(Gfc2RuledSurface,gfc2::engine::EntityFactory)
public:
    Gfc2RuledSurface();
    Gfc2RuledSurface(bool bSetSchema);
    void setApexIndex(const Gfc2Integer& nValue);
    Gfc2Integer getApexIndex() const;
    bool hasApexIndex() const;
    void setRangeV(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRangeV() const;
    bool hasRangeV() const;
    std::shared_ptr<Gfc2Intervald> getRangeVPtr();
    void setRangeU(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRangeU() const;
    bool hasRangeU() const;
    std::shared_ptr<Gfc2Intervald> getRangeUPtr();
    void setDirectrix1(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getDirectrix1() const;
    bool hasDirectrix1() const;
    std::shared_ptr<Gfc2Curve3d> getDirectrix1Ptr();
    void setDirectrix2(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getDirectrix2() const;
    bool hasDirectrix2() const;
    std::shared_ptr<Gfc2Curve3d> getDirectrix2Ptr();

};
#endif

#ifndef GFCPREIMAGECURVE2D_H
#define GFCPREIMAGECURVE2D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcClasses/x3/GfcIntervald.h"
#include "GfcClasses/x3/GfcSurface.h"
#include "GfcClasses/x3/GfcCurve3d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPreimageCurve2d: public GfcCurve2d
{
GFCENGINE_DEC_OBJECT(GfcPreimageCurve2d, gfc::engine::CEntity)
public:
    GfcPreimageCurve2d();
    GfcPreimageCurve2d(bool bSetSchema);
    void setRange(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRange() const;
    bool hasRange() const;
    std::shared_ptr<GfcIntervald> getRangePtr();
    void setReversed(const GfcBoolean& bValue);
    GfcBoolean getReversed() const;
    bool hasReversed() const;
    void setBase(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getBase() const;
    bool hasBase() const;
    std::shared_ptr<GfcSurface> getBasePtr();
    void setCurve(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCurve() const;
    bool hasCurve() const;
    std::shared_ptr<GfcCurve3d> getCurvePtr();
    void setTolerance(const GfcDouble& dValue);
    GfcDouble getTolerance() const;
    bool hasTolerance() const;

};

GFCCLASSES_NAMESPACE_END

#endif

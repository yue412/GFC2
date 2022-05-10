#ifndef GFCOFFSETCURVE2D_H
#define GFCOFFSETCURVE2D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcOffsetCurve2d: public GfcCurve2d
{
GFCENGINE_DEC_OBJECT(GfcOffsetCurve2d, gfc::engine::CEntity)
public:
    GfcOffsetCurve2d();
    GfcOffsetCurve2d(bool bSetSchema);
    void setOffDist(const GfcDouble& dValue);
    GfcDouble getOffDist() const;
    bool hasOffDist() const;
    void setInitCurve(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getInitCurve() const;
    bool hasInitCurve() const;
    std::shared_ptr<GfcCurve2d> getInitCurvePtr();

};

GFCCLASSES_NAMESPACE_END

#endif

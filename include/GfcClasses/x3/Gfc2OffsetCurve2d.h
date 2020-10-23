#ifndef GFC2OFFSETCURVE2D_H
#define GFC2OFFSETCURVE2D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Curve2d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2OffsetCurve2d: public Gfc2Curve2d
{
GFCENGINE_DEC_OBJECT(Gfc2OffsetCurve2d, gfc::engine::CEntity)
public:
    Gfc2OffsetCurve2d();
    Gfc2OffsetCurve2d(bool bSetSchema);
    void setOffDist(const Gfc2Double& dValue);
    Gfc2Double getOffDist() const;
    bool hasOffDist() const;
    void setInitCurve(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getInitCurve() const;
    bool hasInitCurve() const;
    std::shared_ptr<Gfc2Curve2d> getInitCurvePtr();

};

GFCCLASSES_NAMESPACE_END

#endif
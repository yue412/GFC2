#ifndef GFC2OFFSETCURVE2D_H
#define GFC2OFFSETCURVE2D_H

#include "GfcClasses.h"
#include "Gfc2Curve2d.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2OffsetCurve2d: public Gfc2Curve2d
{
GFCENGINE_DEC_OBJECT(Gfc2OffsetCurve2d, gfc::engine::Entity)
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
#endif

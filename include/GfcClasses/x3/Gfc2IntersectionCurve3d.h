#ifndef GFC2INTERSECTIONCURVE3D_H
#define GFC2INTERSECTIONCURVE3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Curve3d.h"
#include "GfcClasses/x3/Gfc2Surface.h"
#include "GfcClasses/x3/Gfc2Intervald.h"
#include "GfcClasses/x3/Gfc2InternalChart.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2IntersectionCurve3d: public Gfc2Curve3d
{
GFCENGINE_DEC_OBJECT(Gfc2IntersectionCurve3d, gfc::engine::CEntity)
public:
    Gfc2IntersectionCurve3d();
    Gfc2IntersectionCurve3d(bool bSetSchema);
    void setBases1(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getBases1() const;
    bool hasBases1() const;
    std::shared_ptr<Gfc2Surface> getBases1Ptr();
    void setBases2(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getBases2() const;
    bool hasBases2() const;
    std::shared_ptr<Gfc2Surface> getBases2Ptr();
    void setRange(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRange() const;
    bool hasRange() const;
    std::shared_ptr<Gfc2Intervald> getRangePtr();
    void setChart(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getChart() const;
    bool hasChart() const;
    std::shared_ptr<Gfc2InternalChart> getChartPtr();

};

GFCCLASSES_NAMESPACE_END

#endif

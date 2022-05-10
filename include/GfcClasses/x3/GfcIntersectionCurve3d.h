#ifndef GFCINTERSECTIONCURVE3D_H
#define GFCINTERSECTIONCURVE3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcCurve3d.h"
#include "GfcClasses/x3/GfcSurface.h"
#include "GfcClasses/x3/GfcIntervald.h"
#include "GfcClasses/x3/GfcInternalChart.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcIntersectionCurve3d: public GfcCurve3d
{
GFCENGINE_DEC_OBJECT(GfcIntersectionCurve3d, gfc::engine::CEntity)
public:
    GfcIntersectionCurve3d();
    GfcIntersectionCurve3d(bool bSetSchema);
    void setBases1(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getBases1() const;
    bool hasBases1() const;
    std::shared_ptr<GfcSurface> getBases1Ptr();
    void setBases2(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getBases2() const;
    bool hasBases2() const;
    std::shared_ptr<GfcSurface> getBases2Ptr();
    void setRange(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRange() const;
    bool hasRange() const;
    std::shared_ptr<GfcIntervald> getRangePtr();
    void setChart(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getChart() const;
    bool hasChart() const;
    std::shared_ptr<GfcInternalChart> getChartPtr();

};

GFCCLASSES_NAMESPACE_END

#endif

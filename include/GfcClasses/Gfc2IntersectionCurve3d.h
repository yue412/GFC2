#ifndef GFC2INTERSECTIONCURVE3D_H
#define GFC2INTERSECTIONCURVE3D_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Curve3d.h"
#include "Gfc2Surface.h"
#include "Gfc2Surface.h"
#include "Gfc2Intervald.h"
#include "Gfc2InternalChart.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2IntersectionCurve3d: public Gfc2Curve3d
{
GFCENGINE_DEC_OBJECT(Gfc2IntersectionCurve3d,gfc2::engine::EntityFactory)
public:
    Gfc2IntersectionCurve3d();
    Gfc2IntersectionCurve3d(bool bSetSchema);
    void setBases1(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getBases1() const;
    bool hasBases1() const;
    std::shared_ptr<Gfc2Surface> getBases1Ptr();
    void setBases2(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getBases2() const;
    bool hasBases2() const;
    std::shared_ptr<Gfc2Surface> getBases2Ptr();
    void setRange(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRange() const;
    bool hasRange() const;
    std::shared_ptr<Gfc2Intervald> getRangePtr();
    void setChart(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getChart() const;
    bool hasChart() const;
    std::shared_ptr<Gfc2InternalChart> getChartPtr();

};
#endif

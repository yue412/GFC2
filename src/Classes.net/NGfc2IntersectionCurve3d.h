#ifndef NGFC2INTERSECTIONCURVE3D_H
#define NGFC2INTERSECTIONCURVE3D_H

#include "NGfc2Curve3d.h"
#include "Gfc2IntersectionCurve3d.h"
#include "NGfc2Surface.h"
#include "NGfc2Intervald.h"
#include "NGfc2InternalChart.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2IntersectionCurve3d: public NGfc2Curve3d
{
public:
    NGfc2IntersectionCurve3d();
    NGfc2IntersectionCurve3d(void* pEntity, bool bOwner);
    void setBases1(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getBases1();
    bool hasBases1();
    NGfc2Surface^ getBases1Ptr();
    void setBases2(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getBases2();
    bool hasBases2();
    NGfc2Surface^ getBases2Ptr();
    void setRange(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getRange();
    bool hasRange();
    NGfc2Intervald^ getRangePtr();
    void setChart(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getChart();
    bool hasChart();
    NGfc2InternalChart^ getChartPtr();

};
#endif

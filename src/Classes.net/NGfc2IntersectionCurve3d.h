#ifndef NGFC2INTERSECTIONCURVE3D_H
#define NGFC2INTERSECTIONCURVE3D_H

#include "NGfc2Curve3d.h"
#include "GfcClasses\x3\Gfc2IntersectionCurve3d.h"
#include "NGfc2Surface.h"
#include "NGfc2Intervald.h"
#include "NGfc2InternalChart.h"

public ref class NGfc2IntersectionCurve3d: public NGfc2Curve3d
{
public:
    NGfc2IntersectionCurve3d();
    NGfc2IntersectionCurve3d(void* pEntity, bool bOwner);
    void setBases1(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getBases1();
    bool hasBases1();
    void setBases2(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getBases2();
    bool hasBases2();
    void setRange(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRange();
    bool hasRange();
    void setChart(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getChart();
    bool hasChart();

};
#endif

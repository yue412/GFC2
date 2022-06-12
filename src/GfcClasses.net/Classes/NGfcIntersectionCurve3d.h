#ifndef NGFCINTERSECTIONCURVE3D_H
#define NGFCINTERSECTIONCURVE3D_H

#include "NGfcCurve3d.h"
#include "GfcClasses\x3\GfcIntersectionCurve3d.h"
#include "NGfcSurface.h"
#include "NGfcIntervald.h"
#include "NGfcInternalChart.h"

public ref class NGfcIntersectionCurve3d: public NGfcCurve3d
{
public:
    NGfcIntersectionCurve3d();
    NGfcIntersectionCurve3d(gfc::engine::CEntity* pEntity, bool bOwner);
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

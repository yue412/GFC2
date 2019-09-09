#ifndef NGFC2INTERSECTIONCURVE3D_H
#define NGFC2INTERSECTIONCURVE3D_H

#include "NGfc2Curve3d.h"
#include "Gfc2IntersectionCurve3d.h"
#include "NGfc2Surface.h"
#include "NGfc2Intervald.h"
#include "NGfc2InternalChart.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2IntersectionCurve3d: public NGfc2Curve3d
{
public:
    NGfc2IntersectionCurve3d();
    NGfc2IntersectionCurve3d(void* pEntity, bool bOwner);
    void setBases1(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getBases1();
    bool hasBases1();
    NGfc2Surface^ getBases1Ptr();
    void setBases2(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getBases2();
    bool hasBases2();
    NGfc2Surface^ getBases2Ptr();
    void setRange(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRange();
    bool hasRange();
    NGfc2Intervald^ getRangePtr();
    void setChart(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getChart();
    bool hasChart();
    NGfc2InternalChart^ getChartPtr();

};
#endif

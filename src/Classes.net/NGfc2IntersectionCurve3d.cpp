#include "StdAfx.h"
#include "NGfc2IntersectionCurve3d.h"
NGfc2IntersectionCurve3d::NGfc2IntersectionCurve3d()
{
    m_pEntity = new Gfc2IntersectionCurve3d;
    m_bOwner = true;
}

NGfc2IntersectionCurve3d::NGfc2IntersectionCurve3d(void* pEntity, bool bOwner):
    NGfc2Curve3d(pEntity, bOwner)
{
}

void NGfc2IntersectionCurve3d::setBases1(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2IntersectionCurve3d*)m_pEntity)->setBases1(nValue);
}

glodon::objectbuf::EntityRef NGfc2IntersectionCurve3d::getBases1()
{
    return ((Gfc2IntersectionCurve3d*)m_pEntity)->getBases1();
}

bool NGfc2IntersectionCurve3d::hasBases1()
{
    return ((Gfc2IntersectionCurve3d*)m_pEntity)->hasBases1();
}

NGfc2Surface^ NGfc2IntersectionCurve3d::getBases1Ptr()
{
    return gcnew NGfc2Surface(((Gfc2IntersectionCurve3d*)m_pEntity)->getBases1Ptr(), false);
}

void NGfc2IntersectionCurve3d::setBases2(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2IntersectionCurve3d*)m_pEntity)->setBases2(nValue);
}

glodon::objectbuf::EntityRef NGfc2IntersectionCurve3d::getBases2()
{
    return ((Gfc2IntersectionCurve3d*)m_pEntity)->getBases2();
}

bool NGfc2IntersectionCurve3d::hasBases2()
{
    return ((Gfc2IntersectionCurve3d*)m_pEntity)->hasBases2();
}

NGfc2Surface^ NGfc2IntersectionCurve3d::getBases2Ptr()
{
    return gcnew NGfc2Surface(((Gfc2IntersectionCurve3d*)m_pEntity)->getBases2Ptr(), false);
}

void NGfc2IntersectionCurve3d::setRange(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2IntersectionCurve3d*)m_pEntity)->setRange(nValue);
}

glodon::objectbuf::EntityRef NGfc2IntersectionCurve3d::getRange()
{
    return ((Gfc2IntersectionCurve3d*)m_pEntity)->getRange();
}

bool NGfc2IntersectionCurve3d::hasRange()
{
    return ((Gfc2IntersectionCurve3d*)m_pEntity)->hasRange();
}

NGfc2Intervald^ NGfc2IntersectionCurve3d::getRangePtr()
{
    return gcnew NGfc2Intervald(((Gfc2IntersectionCurve3d*)m_pEntity)->getRangePtr(), false);
}

void NGfc2IntersectionCurve3d::setChart(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2IntersectionCurve3d*)m_pEntity)->setChart(nValue);
}

glodon::objectbuf::EntityRef NGfc2IntersectionCurve3d::getChart()
{
    return ((Gfc2IntersectionCurve3d*)m_pEntity)->getChart();
}

bool NGfc2IntersectionCurve3d::hasChart()
{
    return ((Gfc2IntersectionCurve3d*)m_pEntity)->hasChart();
}

NGfc2InternalChart^ NGfc2IntersectionCurve3d::getChartPtr()
{
    return gcnew NGfc2InternalChart(((Gfc2IntersectionCurve3d*)m_pEntity)->getChartPtr(), false);
}


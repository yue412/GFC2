#include "NGfc2IntersectionCurve3d.h"

using namespace gfc::classes::x3;

NGfc2IntersectionCurve3d::NGfc2IntersectionCurve3d()
{
    m_pEntity = new Gfc2IntersectionCurve3d;
    m_bOwner = true;
}

NGfc2IntersectionCurve3d::NGfc2IntersectionCurve3d(void* pEntity, bool bOwner):
    NGfc2Curve3d(pEntity, bOwner)
{
}

void NGfc2IntersectionCurve3d::setBases1(gfc::engine::EntityRef nValue)
{
    ((Gfc2IntersectionCurve3d*)m_pEntity)->setBases1(nValue);
}

gfc::engine::EntityRef NGfc2IntersectionCurve3d::getBases1()
{
    return ((Gfc2IntersectionCurve3d*)m_pEntity)->getBases1();
}

bool NGfc2IntersectionCurve3d::hasBases1()
{
    return ((Gfc2IntersectionCurve3d*)m_pEntity)->hasBases1();
}

void NGfc2IntersectionCurve3d::setBases2(gfc::engine::EntityRef nValue)
{
    ((Gfc2IntersectionCurve3d*)m_pEntity)->setBases2(nValue);
}

gfc::engine::EntityRef NGfc2IntersectionCurve3d::getBases2()
{
    return ((Gfc2IntersectionCurve3d*)m_pEntity)->getBases2();
}

bool NGfc2IntersectionCurve3d::hasBases2()
{
    return ((Gfc2IntersectionCurve3d*)m_pEntity)->hasBases2();
}

void NGfc2IntersectionCurve3d::setRange(gfc::engine::EntityRef nValue)
{
    ((Gfc2IntersectionCurve3d*)m_pEntity)->setRange(nValue);
}

gfc::engine::EntityRef NGfc2IntersectionCurve3d::getRange()
{
    return ((Gfc2IntersectionCurve3d*)m_pEntity)->getRange();
}

bool NGfc2IntersectionCurve3d::hasRange()
{
    return ((Gfc2IntersectionCurve3d*)m_pEntity)->hasRange();
}

void NGfc2IntersectionCurve3d::setChart(gfc::engine::EntityRef nValue)
{
    ((Gfc2IntersectionCurve3d*)m_pEntity)->setChart(nValue);
}

gfc::engine::EntityRef NGfc2IntersectionCurve3d::getChart()
{
    return ((Gfc2IntersectionCurve3d*)m_pEntity)->getChart();
}

bool NGfc2IntersectionCurve3d::hasChart()
{
    return ((Gfc2IntersectionCurve3d*)m_pEntity)->hasChart();
}


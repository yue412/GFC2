#include "NGfcIntersectionCurve3d.h"

using namespace gfc::classes::x3;

NGfcIntersectionCurve3d::NGfcIntersectionCurve3d()
{
    m_pEntity = new GfcIntersectionCurve3d;
    m_bOwner = true;
}

NGfcIntersectionCurve3d::NGfcIntersectionCurve3d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcCurve3d(pEntity, bOwner)
{
}

void NGfcIntersectionCurve3d::setBases1(gfc::engine::EntityRef nValue)
{
    ((GfcIntersectionCurve3d*)m_pEntity)->setBases1(nValue);
}

gfc::engine::EntityRef NGfcIntersectionCurve3d::getBases1()
{
    return ((GfcIntersectionCurve3d*)m_pEntity)->getBases1();
}

bool NGfcIntersectionCurve3d::hasBases1()
{
    return ((GfcIntersectionCurve3d*)m_pEntity)->hasBases1();
}

void NGfcIntersectionCurve3d::setBases2(gfc::engine::EntityRef nValue)
{
    ((GfcIntersectionCurve3d*)m_pEntity)->setBases2(nValue);
}

gfc::engine::EntityRef NGfcIntersectionCurve3d::getBases2()
{
    return ((GfcIntersectionCurve3d*)m_pEntity)->getBases2();
}

bool NGfcIntersectionCurve3d::hasBases2()
{
    return ((GfcIntersectionCurve3d*)m_pEntity)->hasBases2();
}

void NGfcIntersectionCurve3d::setRange(gfc::engine::EntityRef nValue)
{
    ((GfcIntersectionCurve3d*)m_pEntity)->setRange(nValue);
}

gfc::engine::EntityRef NGfcIntersectionCurve3d::getRange()
{
    return ((GfcIntersectionCurve3d*)m_pEntity)->getRange();
}

bool NGfcIntersectionCurve3d::hasRange()
{
    return ((GfcIntersectionCurve3d*)m_pEntity)->hasRange();
}

void NGfcIntersectionCurve3d::setChart(gfc::engine::EntityRef nValue)
{
    ((GfcIntersectionCurve3d*)m_pEntity)->setChart(nValue);
}

gfc::engine::EntityRef NGfcIntersectionCurve3d::getChart()
{
    return ((GfcIntersectionCurve3d*)m_pEntity)->getChart();
}

bool NGfcIntersectionCurve3d::hasChart()
{
    return ((GfcIntersectionCurve3d*)m_pEntity)->hasChart();
}


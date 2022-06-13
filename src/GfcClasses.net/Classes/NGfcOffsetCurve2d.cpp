#include "NGfcOffsetCurve2d.h"

using namespace gfc::classes::x3;

NGfcOffsetCurve2d::NGfcOffsetCurve2d()
{
    m_pEntity = new GfcOffsetCurve2d;
    m_bOwner = true;
}

NGfcOffsetCurve2d::NGfcOffsetCurve2d(bool bNoCreate):
    NGfcCurve2d(bNoCreate)
{
}

void NGfcOffsetCurve2d::setOffDist(NGfcDouble dValue)
{
    ((GfcOffsetCurve2d*)m_pEntity)->setOffDist(dValue);
}

NGfcDouble NGfcOffsetCurve2d::getOffDist()
{
    return ((GfcOffsetCurve2d*)m_pEntity)->getOffDist();
}

bool NGfcOffsetCurve2d::hasOffDist()
{
    return ((GfcOffsetCurve2d*)m_pEntity)->hasOffDist();
}

void NGfcOffsetCurve2d::setInitCurve(gfc::engine::EntityRef nValue)
{
    ((GfcOffsetCurve2d*)m_pEntity)->setInitCurve(nValue);
}

gfc::engine::EntityRef NGfcOffsetCurve2d::getInitCurve()
{
    return ((GfcOffsetCurve2d*)m_pEntity)->getInitCurve();
}

bool NGfcOffsetCurve2d::hasInitCurve()
{
    return ((GfcOffsetCurve2d*)m_pEntity)->hasInitCurve();
}


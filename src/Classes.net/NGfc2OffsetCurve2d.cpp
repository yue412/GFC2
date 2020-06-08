#include "StdAfx.h"
#include "NGfc2OffsetCurve2d.h"
NGfc2OffsetCurve2d::NGfc2OffsetCurve2d()
{
    m_pEntity = new Gfc2OffsetCurve2d;
    m_bOwner = true;
}

NGfc2OffsetCurve2d::NGfc2OffsetCurve2d(void* pEntity, bool bOwner):
    NGfc2Curve2d(pEntity, bOwner)
{
}

void NGfc2OffsetCurve2d::setOffDist(NGfc2Double dValue)
{
    ((Gfc2OffsetCurve2d*)m_pEntity)->setOffDist(dValue);
}

NGfc2Double NGfc2OffsetCurve2d::getOffDist()
{
    return ((Gfc2OffsetCurve2d*)m_pEntity)->getOffDist();
}

bool NGfc2OffsetCurve2d::hasOffDist()
{
    return ((Gfc2OffsetCurve2d*)m_pEntity)->hasOffDist();
}

void NGfc2OffsetCurve2d::setInitCurve(gfc::engine::EntityRef nValue)
{
    ((Gfc2OffsetCurve2d*)m_pEntity)->setInitCurve(nValue);
}

gfc::engine::EntityRef NGfc2OffsetCurve2d::getInitCurve()
{
    return ((Gfc2OffsetCurve2d*)m_pEntity)->getInitCurve();
}

bool NGfc2OffsetCurve2d::hasInitCurve()
{
    return ((Gfc2OffsetCurve2d*)m_pEntity)->hasInitCurve();
}

NGfc2Curve2d^ NGfc2OffsetCurve2d::getInitCurvePtr()
{
    return gcnew NGfc2Curve2d(((Gfc2OffsetCurve2d*)m_pEntity)->getInitCurvePtr(), false);
}


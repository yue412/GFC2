#include "StdAfx.h"
#include "NGfc2HermiteCurve2d.h"
NGfc2HermiteCurve2d::NGfc2HermiteCurve2d()
{
    m_pEntity = new Gfc2HermiteCurve2d;
    m_bOwner = true;
}

NGfc2HermiteCurve2d::NGfc2HermiteCurve2d(void* pEntity, bool bOwner):
    NGfc2Curve2d(pEntity, bOwner)
{
}

int NGfc2HermiteCurve2d::getCtrlPtsCount()
{
    return ((Gfc2HermiteCurve2d*)m_pEntity)->getCtrlPtsCount();
}

void NGfc2HermiteCurve2d::clearCtrlPts()
{
    ((Gfc2HermiteCurve2d*)m_pEntity)->clearCtrlPts();
}

void NGfc2HermiteCurve2d::addCtrlPts(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2HermiteCurve2d*)m_pEntity)->addCtrlPts(nValue);
}

glodon::objectbuf::EntityRef NGfc2HermiteCurve2d::getCtrlPts(int nIndex)
{
    return ((Gfc2HermiteCurve2d*)m_pEntity)->getCtrlPts(nIndex);
}

NGfc2HermiteCtrlPt2d^ NGfc2HermiteCurve2d::getCtrlPtsPtr(int nIndex)
{
    return gcnew NGfc2HermiteCtrlPt2d(((Gfc2HermiteCurve2d*)m_pEntity)->getCtrlPtsPtr(nIndex), false);
}


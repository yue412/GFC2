#include "StdAfx.h"
#include "NGfc2HermiteCurve3d.h"
NGfc2HermiteCurve3d::NGfc2HermiteCurve3d()
{
    m_pEntity = new Gfc2HermiteCurve3d;
    m_bOwner = true;
}

NGfc2HermiteCurve3d::NGfc2HermiteCurve3d(void* pEntity, bool bOwner):
    NGfc2Curve3d(pEntity, bOwner)
{
}

int NGfc2HermiteCurve3d::getCtrlPtsCount()
{
    return ((Gfc2HermiteCurve3d*)m_pEntity)->getCtrlPtsCount();
}

void NGfc2HermiteCurve3d::clearCtrlPts()
{
    ((Gfc2HermiteCurve3d*)m_pEntity)->clearCtrlPts();
}

void NGfc2HermiteCurve3d::addCtrlPts(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2HermiteCurve3d*)m_pEntity)->addCtrlPts(nValue);
}

glodon::objectbuf::EntityRef NGfc2HermiteCurve3d::getCtrlPts(int nIndex)
{
    return ((Gfc2HermiteCurve3d*)m_pEntity)->getCtrlPts(nIndex);
}

NGfc2HermiteCtrlPt3d^ NGfc2HermiteCurve3d::getCtrlPtsPtr(int nIndex)
{
    return gcnew NGfc2HermiteCtrlPt3d(((Gfc2HermiteCurve3d*)m_pEntity)->getCtrlPtsPtr(nIndex), false);
}


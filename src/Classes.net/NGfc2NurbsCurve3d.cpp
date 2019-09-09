#include "StdAfx.h"
#include "NGfc2NurbsCurve3d.h"
NGfc2NurbsCurve3d::NGfc2NurbsCurve3d()
{
    m_pEntity = new Gfc2NurbsCurve3d;
    m_bOwner = true;
}

NGfc2NurbsCurve3d::NGfc2NurbsCurve3d(void* pEntity, bool bOwner):
    NGfc2Curve3d(pEntity, bOwner)
{
}

void NGfc2NurbsCurve3d::setDegree(NGfc2Integer nValue)
{
    ((Gfc2NurbsCurve3d*)m_pEntity)->setDegree(nValue);
}

NGfc2Integer NGfc2NurbsCurve3d::getDegree()
{
    return ((Gfc2NurbsCurve3d*)m_pEntity)->getDegree();
}

bool NGfc2NurbsCurve3d::hasDegree()
{
    return ((Gfc2NurbsCurve3d*)m_pEntity)->hasDegree();
}

int NGfc2NurbsCurve3d::getCtrlPtsCount()
{
    return ((Gfc2NurbsCurve3d*)m_pEntity)->getCtrlPtsCount();
}

void NGfc2NurbsCurve3d::clearCtrlPts()
{
    ((Gfc2NurbsCurve3d*)m_pEntity)->clearCtrlPts();
}

void NGfc2NurbsCurve3d::addCtrlPts(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2NurbsCurve3d*)m_pEntity)->addCtrlPts(nValue);
}

glodon::objectbuf::EntityRef NGfc2NurbsCurve3d::getCtrlPts(int nIndex)
{
    return ((Gfc2NurbsCurve3d*)m_pEntity)->getCtrlPts(nIndex);
}

NGfc2NurbsCtrlPt3d^ NGfc2NurbsCurve3d::getCtrlPtsPtr(int nIndex)
{
    return gcnew NGfc2NurbsCtrlPt3d(((Gfc2NurbsCurve3d*)m_pEntity)->getCtrlPtsPtr(nIndex), false);
}

int NGfc2NurbsCurve3d::getKnotsCount()
{
    return ((Gfc2NurbsCurve3d*)m_pEntity)->getKnotsCount();
}

void NGfc2NurbsCurve3d::clearKnots()
{
    ((Gfc2NurbsCurve3d*)m_pEntity)->clearKnots();
}

void NGfc2NurbsCurve3d::addKnots(NGfc2Double dValue)
{
    ((Gfc2NurbsCurve3d*)m_pEntity)->addKnots(dValue);
}

NGfc2Double NGfc2NurbsCurve3d::getKnots(int nIndex)
{
    return ((Gfc2NurbsCurve3d*)m_pEntity)->getKnots(nIndex);
}


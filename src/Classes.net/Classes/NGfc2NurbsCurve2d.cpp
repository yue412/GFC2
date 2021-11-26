#include "NGfc2NurbsCurve2d.h"

using namespace gfc::classes::x3;

NGfc2NurbsCurve2d::NGfc2NurbsCurve2d()
{
    m_pEntity = new Gfc2NurbsCurve2d;
    m_bOwner = true;
}

NGfc2NurbsCurve2d::NGfc2NurbsCurve2d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Curve2d(pEntity, bOwner)
{
}

void NGfc2NurbsCurve2d::setDegree(NGfc2Integer nValue)
{
    ((Gfc2NurbsCurve2d*)m_pEntity)->setDegree(nValue);
}

NGfc2Integer NGfc2NurbsCurve2d::getDegree()
{
    return ((Gfc2NurbsCurve2d*)m_pEntity)->getDegree();
}

bool NGfc2NurbsCurve2d::hasDegree()
{
    return ((Gfc2NurbsCurve2d*)m_pEntity)->hasDegree();
}

int NGfc2NurbsCurve2d::getCtrlPtsCount()
{
    return ((Gfc2NurbsCurve2d*)m_pEntity)->getCtrlPtsCount();
}

void NGfc2NurbsCurve2d::clearCtrlPts()
{
    ((Gfc2NurbsCurve2d*)m_pEntity)->clearCtrlPts();
}

void NGfc2NurbsCurve2d::addCtrlPts(gfc::engine::EntityRef nValue)
{
    ((Gfc2NurbsCurve2d*)m_pEntity)->addCtrlPts(nValue);
}

gfc::engine::EntityRef NGfc2NurbsCurve2d::getCtrlPts(int nIndex)
{
    return ((Gfc2NurbsCurve2d*)m_pEntity)->getCtrlPts(nIndex);
}

int NGfc2NurbsCurve2d::getKnotsCount()
{
    return ((Gfc2NurbsCurve2d*)m_pEntity)->getKnotsCount();
}

void NGfc2NurbsCurve2d::clearKnots()
{
    ((Gfc2NurbsCurve2d*)m_pEntity)->clearKnots();
}

void NGfc2NurbsCurve2d::addKnots(NGfc2Double dValue)
{
    ((Gfc2NurbsCurve2d*)m_pEntity)->addKnots(dValue);
}

NGfc2Double NGfc2NurbsCurve2d::getKnots(int nIndex)
{
    return ((Gfc2NurbsCurve2d*)m_pEntity)->getKnots(nIndex);
}


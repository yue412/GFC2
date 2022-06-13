#include "NGfcNurbsCurve2d.h"

using namespace gfc::classes::x3;

NGfcNurbsCurve2d::NGfcNurbsCurve2d()
{
    m_pEntity = new GfcNurbsCurve2d;
    m_bOwner = true;
}

NGfcNurbsCurve2d::NGfcNurbsCurve2d(bool bNoCreate):
    NGfcCurve2d(bNoCreate)
{
}

void NGfcNurbsCurve2d::setDegree(NGfcInteger nValue)
{
    ((GfcNurbsCurve2d*)m_pEntity)->setDegree(nValue);
}

NGfcInteger NGfcNurbsCurve2d::getDegree()
{
    return ((GfcNurbsCurve2d*)m_pEntity)->getDegree();
}

bool NGfcNurbsCurve2d::hasDegree()
{
    return ((GfcNurbsCurve2d*)m_pEntity)->hasDegree();
}

int NGfcNurbsCurve2d::getCtrlPtsCount()
{
    return ((GfcNurbsCurve2d*)m_pEntity)->getCtrlPtsCount();
}

void NGfcNurbsCurve2d::clearCtrlPts()
{
    ((GfcNurbsCurve2d*)m_pEntity)->clearCtrlPts();
}

void NGfcNurbsCurve2d::addCtrlPts(gfc::engine::EntityRef nValue)
{
    ((GfcNurbsCurve2d*)m_pEntity)->addCtrlPts(nValue);
}

gfc::engine::EntityRef NGfcNurbsCurve2d::getCtrlPts(int nIndex)
{
    return ((GfcNurbsCurve2d*)m_pEntity)->getCtrlPts(nIndex);
}

int NGfcNurbsCurve2d::getKnotsCount()
{
    return ((GfcNurbsCurve2d*)m_pEntity)->getKnotsCount();
}

void NGfcNurbsCurve2d::clearKnots()
{
    ((GfcNurbsCurve2d*)m_pEntity)->clearKnots();
}

void NGfcNurbsCurve2d::addKnots(NGfcDouble dValue)
{
    ((GfcNurbsCurve2d*)m_pEntity)->addKnots(dValue);
}

NGfcDouble NGfcNurbsCurve2d::getKnots(int nIndex)
{
    return ((GfcNurbsCurve2d*)m_pEntity)->getKnots(nIndex);
}


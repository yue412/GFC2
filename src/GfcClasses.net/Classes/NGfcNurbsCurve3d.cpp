#include "NGfcNurbsCurve3d.h"

using namespace gfc::classes::x3;

NGfcNurbsCurve3d::NGfcNurbsCurve3d()
{
    m_pEntity = new GfcNurbsCurve3d;
    m_bOwner = true;
}

NGfcNurbsCurve3d::NGfcNurbsCurve3d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcCurve3d(pEntity, bOwner)
{
}

void NGfcNurbsCurve3d::setDegree(NGfcInteger nValue)
{
    ((GfcNurbsCurve3d*)m_pEntity)->setDegree(nValue);
}

NGfcInteger NGfcNurbsCurve3d::getDegree()
{
    return ((GfcNurbsCurve3d*)m_pEntity)->getDegree();
}

bool NGfcNurbsCurve3d::hasDegree()
{
    return ((GfcNurbsCurve3d*)m_pEntity)->hasDegree();
}

int NGfcNurbsCurve3d::getCtrlPtsCount()
{
    return ((GfcNurbsCurve3d*)m_pEntity)->getCtrlPtsCount();
}

void NGfcNurbsCurve3d::clearCtrlPts()
{
    ((GfcNurbsCurve3d*)m_pEntity)->clearCtrlPts();
}

void NGfcNurbsCurve3d::addCtrlPts(gfc::engine::EntityRef nValue)
{
    ((GfcNurbsCurve3d*)m_pEntity)->addCtrlPts(nValue);
}

gfc::engine::EntityRef NGfcNurbsCurve3d::getCtrlPts(int nIndex)
{
    return ((GfcNurbsCurve3d*)m_pEntity)->getCtrlPts(nIndex);
}

int NGfcNurbsCurve3d::getKnotsCount()
{
    return ((GfcNurbsCurve3d*)m_pEntity)->getKnotsCount();
}

void NGfcNurbsCurve3d::clearKnots()
{
    ((GfcNurbsCurve3d*)m_pEntity)->clearKnots();
}

void NGfcNurbsCurve3d::addKnots(NGfcDouble dValue)
{
    ((GfcNurbsCurve3d*)m_pEntity)->addKnots(dValue);
}

NGfcDouble NGfcNurbsCurve3d::getKnots(int nIndex)
{
    return ((GfcNurbsCurve3d*)m_pEntity)->getKnots(nIndex);
}


#include "NGfcNurbsCtrlPt3d.h"

using namespace gfc::classes::x3;

NGfcNurbsCtrlPt3d::NGfcNurbsCtrlPt3d()
{
    m_pEntity = new GfcNurbsCtrlPt3d;
    m_bOwner = true;
}

NGfcNurbsCtrlPt3d::NGfcNurbsCtrlPt3d(bool bNoCreate):
    NEntity(bNoCreate)
{
}

void NGfcNurbsCtrlPt3d::setPoint(gfc::engine::EntityRef nValue)
{
    ((GfcNurbsCtrlPt3d*)m_pEntity)->setPoint(nValue);
}

gfc::engine::EntityRef NGfcNurbsCtrlPt3d::getPoint()
{
    return ((GfcNurbsCtrlPt3d*)m_pEntity)->getPoint();
}

bool NGfcNurbsCtrlPt3d::hasPoint()
{
    return ((GfcNurbsCtrlPt3d*)m_pEntity)->hasPoint();
}

void NGfcNurbsCtrlPt3d::setWeight(NGfcDouble dValue)
{
    ((GfcNurbsCtrlPt3d*)m_pEntity)->setWeight(dValue);
}

NGfcDouble NGfcNurbsCtrlPt3d::getWeight()
{
    return ((GfcNurbsCtrlPt3d*)m_pEntity)->getWeight();
}

bool NGfcNurbsCtrlPt3d::hasWeight()
{
    return ((GfcNurbsCtrlPt3d*)m_pEntity)->hasWeight();
}


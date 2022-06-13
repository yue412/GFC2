#include "NGfcNurbsCtrlPt2d.h"

using namespace gfc::classes::x3;

NGfcNurbsCtrlPt2d::NGfcNurbsCtrlPt2d()
{
    m_pEntity = new GfcNurbsCtrlPt2d;
    m_bOwner = true;
}

NGfcNurbsCtrlPt2d::NGfcNurbsCtrlPt2d(bool bNoCreate):
    NEntity(bNoCreate)
{
}

void NGfcNurbsCtrlPt2d::setPoint(gfc::engine::EntityRef nValue)
{
    ((GfcNurbsCtrlPt2d*)m_pEntity)->setPoint(nValue);
}

gfc::engine::EntityRef NGfcNurbsCtrlPt2d::getPoint()
{
    return ((GfcNurbsCtrlPt2d*)m_pEntity)->getPoint();
}

bool NGfcNurbsCtrlPt2d::hasPoint()
{
    return ((GfcNurbsCtrlPt2d*)m_pEntity)->hasPoint();
}

void NGfcNurbsCtrlPt2d::setWeight(NGfcDouble dValue)
{
    ((GfcNurbsCtrlPt2d*)m_pEntity)->setWeight(dValue);
}

NGfcDouble NGfcNurbsCtrlPt2d::getWeight()
{
    return ((GfcNurbsCtrlPt2d*)m_pEntity)->getWeight();
}

bool NGfcNurbsCtrlPt2d::hasWeight()
{
    return ((GfcNurbsCtrlPt2d*)m_pEntity)->hasWeight();
}


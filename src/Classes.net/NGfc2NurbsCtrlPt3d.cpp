#include "NGfc2NurbsCtrlPt3d.h"

using namespace gfc::classes::x3;

NGfc2NurbsCtrlPt3d::NGfc2NurbsCtrlPt3d()
{
    m_pEntity = new Gfc2NurbsCtrlPt3d;
    m_bOwner = true;
}

NGfc2NurbsCtrlPt3d::NGfc2NurbsCtrlPt3d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

void NGfc2NurbsCtrlPt3d::setPoint(gfc::engine::EntityRef nValue)
{
    ((Gfc2NurbsCtrlPt3d*)m_pEntity)->setPoint(nValue);
}

gfc::engine::EntityRef NGfc2NurbsCtrlPt3d::getPoint()
{
    return ((Gfc2NurbsCtrlPt3d*)m_pEntity)->getPoint();
}

bool NGfc2NurbsCtrlPt3d::hasPoint()
{
    return ((Gfc2NurbsCtrlPt3d*)m_pEntity)->hasPoint();
}

void NGfc2NurbsCtrlPt3d::setWeight(NGfc2Double dValue)
{
    ((Gfc2NurbsCtrlPt3d*)m_pEntity)->setWeight(dValue);
}

NGfc2Double NGfc2NurbsCtrlPt3d::getWeight()
{
    return ((Gfc2NurbsCtrlPt3d*)m_pEntity)->getWeight();
}

bool NGfc2NurbsCtrlPt3d::hasWeight()
{
    return ((Gfc2NurbsCtrlPt3d*)m_pEntity)->hasWeight();
}


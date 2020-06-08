#include "StdAfx.h"
#include "NGfc2NurbsCtrlPt2d.h"
NGfc2NurbsCtrlPt2d::NGfc2NurbsCtrlPt2d()
{
    m_pEntity = new Gfc2NurbsCtrlPt2d;
    m_bOwner = true;
}

NGfc2NurbsCtrlPt2d::NGfc2NurbsCtrlPt2d(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2NurbsCtrlPt2d::setPoint(gfc::engine::EntityRef nValue)
{
    ((Gfc2NurbsCtrlPt2d*)m_pEntity)->setPoint(nValue);
}

gfc::engine::EntityRef NGfc2NurbsCtrlPt2d::getPoint()
{
    return ((Gfc2NurbsCtrlPt2d*)m_pEntity)->getPoint();
}

bool NGfc2NurbsCtrlPt2d::hasPoint()
{
    return ((Gfc2NurbsCtrlPt2d*)m_pEntity)->hasPoint();
}

NGfc2Vector2d^ NGfc2NurbsCtrlPt2d::getPointPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2NurbsCtrlPt2d*)m_pEntity)->getPointPtr(), false);
}

void NGfc2NurbsCtrlPt2d::setWeight(NGfc2Double dValue)
{
    ((Gfc2NurbsCtrlPt2d*)m_pEntity)->setWeight(dValue);
}

NGfc2Double NGfc2NurbsCtrlPt2d::getWeight()
{
    return ((Gfc2NurbsCtrlPt2d*)m_pEntity)->getWeight();
}

bool NGfc2NurbsCtrlPt2d::hasWeight()
{
    return ((Gfc2NurbsCtrlPt2d*)m_pEntity)->hasWeight();
}


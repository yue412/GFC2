#include "StdAfx.h"
#include "NGfc2NurbsCtrlPt3d.h"
NGfc2NurbsCtrlPt3d::NGfc2NurbsCtrlPt3d()
{
    m_pEntity = new Gfc2NurbsCtrlPt3d;
    m_bOwner = true;
}

NGfc2NurbsCtrlPt3d::NGfc2NurbsCtrlPt3d(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2NurbsCtrlPt3d::setPoint(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2NurbsCtrlPt3d*)m_pEntity)->setPoint(nValue);
}

glodon::objectbuf::EntityRef NGfc2NurbsCtrlPt3d::getPoint()
{
    return ((Gfc2NurbsCtrlPt3d*)m_pEntity)->getPoint();
}

bool NGfc2NurbsCtrlPt3d::hasPoint()
{
    return ((Gfc2NurbsCtrlPt3d*)m_pEntity)->hasPoint();
}

NGfc2Vector3d^ NGfc2NurbsCtrlPt3d::getPointPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2NurbsCtrlPt3d*)m_pEntity)->getPointPtr(), false);
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


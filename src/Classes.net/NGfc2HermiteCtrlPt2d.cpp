#include "StdAfx.h"
#include "NGfc2HermiteCtrlPt2d.h"
NGfc2HermiteCtrlPt2d::NGfc2HermiteCtrlPt2d()
{
    m_pEntity = new Gfc2HermiteCtrlPt2d;
    m_bOwner = true;
}

NGfc2HermiteCtrlPt2d::NGfc2HermiteCtrlPt2d(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2HermiteCtrlPt2d::setPoint(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2HermiteCtrlPt2d*)m_pEntity)->setPoint(nValue);
}

glodon::objectbuf::EntityRef NGfc2HermiteCtrlPt2d::getPoint()
{
    return ((Gfc2HermiteCtrlPt2d*)m_pEntity)->getPoint();
}

bool NGfc2HermiteCtrlPt2d::hasPoint()
{
    return ((Gfc2HermiteCtrlPt2d*)m_pEntity)->hasPoint();
}

NGfc2Vector2d^ NGfc2HermiteCtrlPt2d::getPointPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2HermiteCtrlPt2d*)m_pEntity)->getPointPtr(), false);
}

void NGfc2HermiteCtrlPt2d::setTangent(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2HermiteCtrlPt2d*)m_pEntity)->setTangent(nValue);
}

glodon::objectbuf::EntityRef NGfc2HermiteCtrlPt2d::getTangent()
{
    return ((Gfc2HermiteCtrlPt2d*)m_pEntity)->getTangent();
}

bool NGfc2HermiteCtrlPt2d::hasTangent()
{
    return ((Gfc2HermiteCtrlPt2d*)m_pEntity)->hasTangent();
}

NGfc2Vector2d^ NGfc2HermiteCtrlPt2d::getTangentPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2HermiteCtrlPt2d*)m_pEntity)->getTangentPtr(), false);
}

void NGfc2HermiteCtrlPt2d::setParameter(NGfc2Double dValue)
{
    ((Gfc2HermiteCtrlPt2d*)m_pEntity)->setParameter(dValue);
}

NGfc2Double NGfc2HermiteCtrlPt2d::getParameter()
{
    return ((Gfc2HermiteCtrlPt2d*)m_pEntity)->getParameter();
}

bool NGfc2HermiteCtrlPt2d::hasParameter()
{
    return ((Gfc2HermiteCtrlPt2d*)m_pEntity)->hasParameter();
}


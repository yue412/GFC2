#include "StdAfx.h"
#include "NGfc2HermiteCtrlPt3d.h"
NGfc2HermiteCtrlPt3d::NGfc2HermiteCtrlPt3d()
{
    m_pEntity = new Gfc2HermiteCtrlPt3d;
    m_bOwner = true;
}

NGfc2HermiteCtrlPt3d::NGfc2HermiteCtrlPt3d(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2HermiteCtrlPt3d::setPoint(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2HermiteCtrlPt3d*)m_pEntity)->setPoint(nValue);
}

glodon::objectbuf::EntityRef NGfc2HermiteCtrlPt3d::getPoint()
{
    return ((Gfc2HermiteCtrlPt3d*)m_pEntity)->getPoint();
}

bool NGfc2HermiteCtrlPt3d::hasPoint()
{
    return ((Gfc2HermiteCtrlPt3d*)m_pEntity)->hasPoint();
}

NGfc2Vector3d^ NGfc2HermiteCtrlPt3d::getPointPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2HermiteCtrlPt3d*)m_pEntity)->getPointPtr(), false);
}

void NGfc2HermiteCtrlPt3d::setTangent(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2HermiteCtrlPt3d*)m_pEntity)->setTangent(nValue);
}

glodon::objectbuf::EntityRef NGfc2HermiteCtrlPt3d::getTangent()
{
    return ((Gfc2HermiteCtrlPt3d*)m_pEntity)->getTangent();
}

bool NGfc2HermiteCtrlPt3d::hasTangent()
{
    return ((Gfc2HermiteCtrlPt3d*)m_pEntity)->hasTangent();
}

NGfc2Vector3d^ NGfc2HermiteCtrlPt3d::getTangentPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2HermiteCtrlPt3d*)m_pEntity)->getTangentPtr(), false);
}

void NGfc2HermiteCtrlPt3d::setParameter(NGfc2Double dValue)
{
    ((Gfc2HermiteCtrlPt3d*)m_pEntity)->setParameter(dValue);
}

NGfc2Double NGfc2HermiteCtrlPt3d::getParameter()
{
    return ((Gfc2HermiteCtrlPt3d*)m_pEntity)->getParameter();
}

bool NGfc2HermiteCtrlPt3d::hasParameter()
{
    return ((Gfc2HermiteCtrlPt3d*)m_pEntity)->hasParameter();
}


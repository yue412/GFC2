#include "StdAfx.h"
#include "NGfc2SimpleVertex.h"
NGfc2SimpleVertex::NGfc2SimpleVertex()
{
    m_pEntity = new Gfc2SimpleVertex;
    m_bOwner = true;
}

NGfc2SimpleVertex::NGfc2SimpleVertex(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2SimpleVertex::setPoint(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SimpleVertex*)m_pEntity)->setPoint(nValue);
}

glodon::objectbuf::EntityRef NGfc2SimpleVertex::getPoint()
{
    return ((Gfc2SimpleVertex*)m_pEntity)->getPoint();
}

bool NGfc2SimpleVertex::hasPoint()
{
    return ((Gfc2SimpleVertex*)m_pEntity)->hasPoint();
}

NGfc2Vector2d^ NGfc2SimpleVertex::getPointPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2SimpleVertex*)m_pEntity)->getPointPtr(), false);
}

void NGfc2SimpleVertex::setRadius(NGfc2Double dValue)
{
    ((Gfc2SimpleVertex*)m_pEntity)->setRadius(dValue);
}

NGfc2Double NGfc2SimpleVertex::getRadius()
{
    return ((Gfc2SimpleVertex*)m_pEntity)->getRadius();
}

bool NGfc2SimpleVertex::hasRadius()
{
    return ((Gfc2SimpleVertex*)m_pEntity)->hasRadius();
}

void NGfc2SimpleVertex::setArcType(NGfc2ArcType nValue)
{
    ((Gfc2SimpleVertex*)m_pEntity)->setArcType((Gfc2ArcType)nValue);
}

NGfc2ArcType NGfc2SimpleVertex::getArcType()
{
    return (NGfc2ArcType)((Gfc2SimpleVertex*)m_pEntity)->getArcType();
}

bool NGfc2SimpleVertex::hasArcType()
{
    return ((Gfc2SimpleVertex*)m_pEntity)->hasArcType();
}


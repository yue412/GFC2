#include "NGfc2SimpleVertex.h"

using namespace gfc::classes::x3;

NGfc2SimpleVertex::NGfc2SimpleVertex()
{
    m_pEntity = new Gfc2SimpleVertex;
    m_bOwner = true;
}

NGfc2SimpleVertex::NGfc2SimpleVertex(void* pEntity, bool bOwner):
    NGfc2Topology(pEntity, bOwner)
{
}

void NGfc2SimpleVertex::setPoint(gfc::engine::EntityRef nValue)
{
    ((Gfc2SimpleVertex*)m_pEntity)->setPoint(nValue);
}

gfc::engine::EntityRef NGfc2SimpleVertex::getPoint()
{
    return ((Gfc2SimpleVertex*)m_pEntity)->getPoint();
}

bool NGfc2SimpleVertex::hasPoint()
{
    return ((Gfc2SimpleVertex*)m_pEntity)->hasPoint();
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


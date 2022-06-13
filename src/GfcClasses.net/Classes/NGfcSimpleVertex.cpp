#include "NGfcSimpleVertex.h"

using namespace gfc::classes::x3;

NGfcSimpleVertex::NGfcSimpleVertex()
{
    m_pEntity = new GfcSimpleVertex;
    m_bOwner = true;
}

NGfcSimpleVertex::NGfcSimpleVertex(bool bNoCreate):
    NGfcTopology(bNoCreate)
{
}

void NGfcSimpleVertex::setPoint(gfc::engine::EntityRef nValue)
{
    ((GfcSimpleVertex*)m_pEntity)->setPoint(nValue);
}

gfc::engine::EntityRef NGfcSimpleVertex::getPoint()
{
    return ((GfcSimpleVertex*)m_pEntity)->getPoint();
}

bool NGfcSimpleVertex::hasPoint()
{
    return ((GfcSimpleVertex*)m_pEntity)->hasPoint();
}

void NGfcSimpleVertex::setRadius(NGfcDouble dValue)
{
    ((GfcSimpleVertex*)m_pEntity)->setRadius(dValue);
}

NGfcDouble NGfcSimpleVertex::getRadius()
{
    return ((GfcSimpleVertex*)m_pEntity)->getRadius();
}

bool NGfcSimpleVertex::hasRadius()
{
    return ((GfcSimpleVertex*)m_pEntity)->hasRadius();
}

void NGfcSimpleVertex::setArcType(NGfcArcType nValue)
{
    ((GfcSimpleVertex*)m_pEntity)->setArcType((GfcArcType)nValue);
}

NGfcArcType NGfcSimpleVertex::getArcType()
{
    return (NGfcArcType)((GfcSimpleVertex*)m_pEntity)->getArcType();
}

bool NGfcSimpleVertex::hasArcType()
{
    return ((GfcSimpleVertex*)m_pEntity)->hasArcType();
}


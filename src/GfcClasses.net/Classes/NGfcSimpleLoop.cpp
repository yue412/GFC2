#include "NGfcSimpleLoop.h"

using namespace gfc::classes::x3;

NGfcSimpleLoop::NGfcSimpleLoop()
{
    m_pEntity = new GfcSimpleLoop;
    m_bOwner = true;
}

NGfcSimpleLoop::NGfcSimpleLoop(bool bNoCreate):
    NGfcTopology(bNoCreate)
{
}

int NGfcSimpleLoop::getVertexesCount()
{
    return ((GfcSimpleLoop*)m_pEntity)->getVertexesCount();
}

void NGfcSimpleLoop::clearVertexes()
{
    ((GfcSimpleLoop*)m_pEntity)->clearVertexes();
}

void NGfcSimpleLoop::addVertexes(gfc::engine::EntityRef nValue)
{
    ((GfcSimpleLoop*)m_pEntity)->addVertexes(nValue);
}

gfc::engine::EntityRef NGfcSimpleLoop::getVertexes(int nIndex)
{
    return ((GfcSimpleLoop*)m_pEntity)->getVertexes(nIndex);
}


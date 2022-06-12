#include "NGfcPolyhedralLoop.h"

using namespace gfc::classes::x3;

NGfcPolyhedralLoop::NGfcPolyhedralLoop()
{
    m_pEntity = new GfcPolyhedralLoop;
    m_bOwner = true;
}

NGfcPolyhedralLoop::NGfcPolyhedralLoop(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcTopology(pEntity, bOwner)
{
}

int NGfcPolyhedralLoop::getEdgesCount()
{
    return ((GfcPolyhedralLoop*)m_pEntity)->getEdgesCount();
}

void NGfcPolyhedralLoop::clearEdges()
{
    ((GfcPolyhedralLoop*)m_pEntity)->clearEdges();
}

void NGfcPolyhedralLoop::addEdges(gfc::engine::EntityRef nValue)
{
    ((GfcPolyhedralLoop*)m_pEntity)->addEdges(nValue);
}

gfc::engine::EntityRef NGfcPolyhedralLoop::getEdges(int nIndex)
{
    return ((GfcPolyhedralLoop*)m_pEntity)->getEdges(nIndex);
}


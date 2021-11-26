#include "NGfc2PolyhedralLoop.h"

using namespace gfc::classes::x3;

NGfc2PolyhedralLoop::NGfc2PolyhedralLoop()
{
    m_pEntity = new Gfc2PolyhedralLoop;
    m_bOwner = true;
}

NGfc2PolyhedralLoop::NGfc2PolyhedralLoop(void* pEntity, bool bOwner):
    NGfc2Topology(pEntity, bOwner)
{
}

int NGfc2PolyhedralLoop::getEdgesCount()
{
    return ((Gfc2PolyhedralLoop*)m_pEntity)->getEdgesCount();
}

void NGfc2PolyhedralLoop::clearEdges()
{
    ((Gfc2PolyhedralLoop*)m_pEntity)->clearEdges();
}

void NGfc2PolyhedralLoop::addEdges(gfc::engine::EntityRef nValue)
{
    ((Gfc2PolyhedralLoop*)m_pEntity)->addEdges(nValue);
}

gfc::engine::EntityRef NGfc2PolyhedralLoop::getEdges(int nIndex)
{
    return ((Gfc2PolyhedralLoop*)m_pEntity)->getEdges(nIndex);
}


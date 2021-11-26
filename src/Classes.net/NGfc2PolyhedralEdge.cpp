#include "NGfc2PolyhedralEdge.h"

using namespace gfc::classes::x3;

NGfc2PolyhedralEdge::NGfc2PolyhedralEdge()
{
    m_pEntity = new Gfc2PolyhedralEdge;
    m_bOwner = true;
}

NGfc2PolyhedralEdge::NGfc2PolyhedralEdge(void* pEntity, bool bOwner):
    NGfc2Topology(pEntity, bOwner)
{
}

void NGfc2PolyhedralEdge::setStartVertexIndex(NGfc2Integer nValue)
{
    ((Gfc2PolyhedralEdge*)m_pEntity)->setStartVertexIndex(nValue);
}

NGfc2Integer NGfc2PolyhedralEdge::getStartVertexIndex()
{
    return ((Gfc2PolyhedralEdge*)m_pEntity)->getStartVertexIndex();
}

bool NGfc2PolyhedralEdge::hasStartVertexIndex()
{
    return ((Gfc2PolyhedralEdge*)m_pEntity)->hasStartVertexIndex();
}

void NGfc2PolyhedralEdge::setEndVertexIndex(NGfc2Integer nValue)
{
    ((Gfc2PolyhedralEdge*)m_pEntity)->setEndVertexIndex(nValue);
}

NGfc2Integer NGfc2PolyhedralEdge::getEndVertexIndex()
{
    return ((Gfc2PolyhedralEdge*)m_pEntity)->getEndVertexIndex();
}

bool NGfc2PolyhedralEdge::hasEndVertexIndex()
{
    return ((Gfc2PolyhedralEdge*)m_pEntity)->hasEndVertexIndex();
}


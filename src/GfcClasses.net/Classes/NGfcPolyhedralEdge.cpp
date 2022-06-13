#include "NGfcPolyhedralEdge.h"

using namespace gfc::classes::x3;

NGfcPolyhedralEdge::NGfcPolyhedralEdge()
{
    m_pEntity = new GfcPolyhedralEdge;
    m_bOwner = true;
}

NGfcPolyhedralEdge::NGfcPolyhedralEdge(bool bNoCreate):
    NGfcTopology(bNoCreate)
{
}

void NGfcPolyhedralEdge::setStartVertexIndex(NGfcInteger nValue)
{
    ((GfcPolyhedralEdge*)m_pEntity)->setStartVertexIndex(nValue);
}

NGfcInteger NGfcPolyhedralEdge::getStartVertexIndex()
{
    return ((GfcPolyhedralEdge*)m_pEntity)->getStartVertexIndex();
}

bool NGfcPolyhedralEdge::hasStartVertexIndex()
{
    return ((GfcPolyhedralEdge*)m_pEntity)->hasStartVertexIndex();
}

void NGfcPolyhedralEdge::setEndVertexIndex(NGfcInteger nValue)
{
    ((GfcPolyhedralEdge*)m_pEntity)->setEndVertexIndex(nValue);
}

NGfcInteger NGfcPolyhedralEdge::getEndVertexIndex()
{
    return ((GfcPolyhedralEdge*)m_pEntity)->getEndVertexIndex();
}

bool NGfcPolyhedralEdge::hasEndVertexIndex()
{
    return ((GfcPolyhedralEdge*)m_pEntity)->hasEndVertexIndex();
}


#include "NGfcCoedge.h"

using namespace gfc::classes::x3;

NGfcCoedge::NGfcCoedge()
{
    m_pEntity = new GfcCoedge;
    m_bOwner = true;
}

NGfcCoedge::NGfcCoedge(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcTopology(pEntity, bOwner)
{
}

void NGfcCoedge::setCurve(gfc::engine::EntityRef nValue)
{
    ((GfcCoedge*)m_pEntity)->setCurve(nValue);
}

gfc::engine::EntityRef NGfcCoedge::getCurve()
{
    return ((GfcCoedge*)m_pEntity)->getCurve();
}

bool NGfcCoedge::hasCurve()
{
    return ((GfcCoedge*)m_pEntity)->hasCurve();
}

void NGfcCoedge::setEdgeIndex(NGfcInteger nValue)
{
    ((GfcCoedge*)m_pEntity)->setEdgeIndex(nValue);
}

NGfcInteger NGfcCoedge::getEdgeIndex()
{
    return ((GfcCoedge*)m_pEntity)->getEdgeIndex();
}

bool NGfcCoedge::hasEdgeIndex()
{
    return ((GfcCoedge*)m_pEntity)->hasEdgeIndex();
}

void NGfcCoedge::setEdgeSameDir(NGfcBoolean bValue)
{
    ((GfcCoedge*)m_pEntity)->setEdgeSameDir(bValue);
}

NGfcBoolean NGfcCoedge::getEdgeSameDir()
{
    return ((GfcCoedge*)m_pEntity)->getEdgeSameDir();
}

bool NGfcCoedge::hasEdgeSameDir()
{
    return ((GfcCoedge*)m_pEntity)->hasEdgeSameDir();
}


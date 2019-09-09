#include "StdAfx.h"
#include "NGfc2PolyhedralLoop.h"
NGfc2PolyhedralLoop::NGfc2PolyhedralLoop()
{
    m_pEntity = new Gfc2PolyhedralLoop;
    m_bOwner = true;
}

NGfc2PolyhedralLoop::NGfc2PolyhedralLoop(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
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

void NGfc2PolyhedralLoop::addEdges(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2PolyhedralLoop*)m_pEntity)->addEdges(nValue);
}

glodon::objectbuf::EntityRef NGfc2PolyhedralLoop::getEdges(int nIndex)
{
    return ((Gfc2PolyhedralLoop*)m_pEntity)->getEdges(nIndex);
}

NGfc2PolyhedralEdge^ NGfc2PolyhedralLoop::getEdgesPtr(int nIndex)
{
    return gcnew NGfc2PolyhedralEdge(((Gfc2PolyhedralLoop*)m_pEntity)->getEdgesPtr(nIndex), false);
}


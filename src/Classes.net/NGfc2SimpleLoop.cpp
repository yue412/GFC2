#include "StdAfx.h"
#include "NGfc2SimpleLoop.h"
NGfc2SimpleLoop::NGfc2SimpleLoop()
{
    m_pEntity = new Gfc2SimpleLoop;
    m_bOwner = true;
}

NGfc2SimpleLoop::NGfc2SimpleLoop(void* pEntity, bool bOwner):
    NGfc2Topology(pEntity, bOwner)
{
}

int NGfc2SimpleLoop::getVertexesCount()
{
    return ((Gfc2SimpleLoop*)m_pEntity)->getVertexesCount();
}

void NGfc2SimpleLoop::clearVertexes()
{
    ((Gfc2SimpleLoop*)m_pEntity)->clearVertexes();
}

void NGfc2SimpleLoop::addVertexes(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SimpleLoop*)m_pEntity)->addVertexes(nValue);
}

glodon::objectbuf::EntityRef NGfc2SimpleLoop::getVertexes(int nIndex)
{
    return ((Gfc2SimpleLoop*)m_pEntity)->getVertexes(nIndex);
}

NGfc2SimpleVertex^ NGfc2SimpleLoop::getVertexesPtr(int nIndex)
{
    return gcnew NGfc2SimpleVertex(((Gfc2SimpleLoop*)m_pEntity)->getVertexesPtr(nIndex), false);
}


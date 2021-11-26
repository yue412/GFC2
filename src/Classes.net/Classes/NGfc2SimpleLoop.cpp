#include "NGfc2SimpleLoop.h"

using namespace gfc::classes::x3;

NGfc2SimpleLoop::NGfc2SimpleLoop()
{
    m_pEntity = new Gfc2SimpleLoop;
    m_bOwner = true;
}

NGfc2SimpleLoop::NGfc2SimpleLoop(gfc::engine::CEntity* pEntity, bool bOwner):
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

void NGfc2SimpleLoop::addVertexes(gfc::engine::EntityRef nValue)
{
    ((Gfc2SimpleLoop*)m_pEntity)->addVertexes(nValue);
}

gfc::engine::EntityRef NGfc2SimpleLoop::getVertexes(int nIndex)
{
    return ((Gfc2SimpleLoop*)m_pEntity)->getVertexes(nIndex);
}


#include "NGfc2CoedgeList.h"

using namespace gfc::classes::x3;

NGfc2CoedgeList::NGfc2CoedgeList()
{
    m_pEntity = new Gfc2CoedgeList;
    m_bOwner = true;
}

NGfc2CoedgeList::NGfc2CoedgeList(void* pEntity, bool bOwner):
    NGfc2Topology(pEntity, bOwner)
{
}

int NGfc2CoedgeList::getCoedgesCount()
{
    return ((Gfc2CoedgeList*)m_pEntity)->getCoedgesCount();
}

void NGfc2CoedgeList::clearCoedges()
{
    ((Gfc2CoedgeList*)m_pEntity)->clearCoedges();
}

void NGfc2CoedgeList::addCoedges(gfc::engine::EntityRef nValue)
{
    ((Gfc2CoedgeList*)m_pEntity)->addCoedges(nValue);
}

gfc::engine::EntityRef NGfc2CoedgeList::getCoedges(int nIndex)
{
    return ((Gfc2CoedgeList*)m_pEntity)->getCoedges(nIndex);
}


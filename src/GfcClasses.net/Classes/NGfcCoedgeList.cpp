#include "NGfcCoedgeList.h"

using namespace gfc::classes::x3;

NGfcCoedgeList::NGfcCoedgeList()
{
    m_pEntity = new GfcCoedgeList;
    m_bOwner = true;
}

NGfcCoedgeList::NGfcCoedgeList(bool bNoCreate):
    NGfcTopology(bNoCreate)
{
}

int NGfcCoedgeList::getCoedgesCount()
{
    return ((GfcCoedgeList*)m_pEntity)->getCoedgesCount();
}

void NGfcCoedgeList::clearCoedges()
{
    ((GfcCoedgeList*)m_pEntity)->clearCoedges();
}

void NGfcCoedgeList::addCoedges(gfc::engine::EntityRef nValue)
{
    ((GfcCoedgeList*)m_pEntity)->addCoedges(nValue);
}

gfc::engine::EntityRef NGfcCoedgeList::getCoedges(int nIndex)
{
    return ((GfcCoedgeList*)m_pEntity)->getCoedges(nIndex);
}


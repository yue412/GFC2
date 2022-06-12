#include "NGfcCoedgeListEx.h"

using namespace gfc::classes::x3;

NGfcCoedgeListEx::NGfcCoedgeListEx()
{
    m_pEntity = new GfcCoedgeListEx;
    m_bOwner = true;
}

NGfcCoedgeListEx::NGfcCoedgeListEx(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcTopology(pEntity, bOwner)
{
}

int NGfcCoedgeListEx::getCoedgeExsCount()
{
    return ((GfcCoedgeListEx*)m_pEntity)->getCoedgeExsCount();
}

void NGfcCoedgeListEx::clearCoedgeExs()
{
    ((GfcCoedgeListEx*)m_pEntity)->clearCoedgeExs();
}

void NGfcCoedgeListEx::addCoedgeExs(gfc::engine::EntityRef nValue)
{
    ((GfcCoedgeListEx*)m_pEntity)->addCoedgeExs(nValue);
}

gfc::engine::EntityRef NGfcCoedgeListEx::getCoedgeExs(int nIndex)
{
    return ((GfcCoedgeListEx*)m_pEntity)->getCoedgeExs(nIndex);
}


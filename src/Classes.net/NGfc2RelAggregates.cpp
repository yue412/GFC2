#include "NGfc2RelAggregates.h"

using namespace gfc::classes::x3;

NGfc2RelAggregates::NGfc2RelAggregates()
{
    m_pEntity = new Gfc2RelAggregates;
    m_bOwner = true;
}

NGfc2RelAggregates::NGfc2RelAggregates(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2RelDecomposes(pEntity, bOwner)
{
}

void NGfc2RelAggregates::setRelatingObject(gfc::engine::EntityRef nValue)
{
    ((Gfc2RelAggregates*)m_pEntity)->setRelatingObject(nValue);
}

gfc::engine::EntityRef NGfc2RelAggregates::getRelatingObject()
{
    return ((Gfc2RelAggregates*)m_pEntity)->getRelatingObject();
}

bool NGfc2RelAggregates::hasRelatingObject()
{
    return ((Gfc2RelAggregates*)m_pEntity)->hasRelatingObject();
}

int NGfc2RelAggregates::getRelatedObjectsCount()
{
    return ((Gfc2RelAggregates*)m_pEntity)->getRelatedObjectsCount();
}

void NGfc2RelAggregates::clearRelatedObjects()
{
    ((Gfc2RelAggregates*)m_pEntity)->clearRelatedObjects();
}

void NGfc2RelAggregates::addRelatedObjects(gfc::engine::EntityRef nValue)
{
    ((Gfc2RelAggregates*)m_pEntity)->addRelatedObjects(nValue);
}

gfc::engine::EntityRef NGfc2RelAggregates::getRelatedObjects(int nIndex)
{
    return ((Gfc2RelAggregates*)m_pEntity)->getRelatedObjects(nIndex);
}


#include "NGfcRelAggregates.h"

using namespace gfc::classes::x3;

NGfcRelAggregates::NGfcRelAggregates()
{
    m_pEntity = new GfcRelAggregates;
    m_bOwner = true;
}

NGfcRelAggregates::NGfcRelAggregates(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcRelDecomposes(pEntity, bOwner)
{
}

void NGfcRelAggregates::setRelatingObject(gfc::engine::EntityRef nValue)
{
    ((GfcRelAggregates*)m_pEntity)->setRelatingObject(nValue);
}

gfc::engine::EntityRef NGfcRelAggregates::getRelatingObject()
{
    return ((GfcRelAggregates*)m_pEntity)->getRelatingObject();
}

bool NGfcRelAggregates::hasRelatingObject()
{
    return ((GfcRelAggregates*)m_pEntity)->hasRelatingObject();
}

int NGfcRelAggregates::getRelatedObjectsCount()
{
    return ((GfcRelAggregates*)m_pEntity)->getRelatedObjectsCount();
}

void NGfcRelAggregates::clearRelatedObjects()
{
    ((GfcRelAggregates*)m_pEntity)->clearRelatedObjects();
}

void NGfcRelAggregates::addRelatedObjects(gfc::engine::EntityRef nValue)
{
    ((GfcRelAggregates*)m_pEntity)->addRelatedObjects(nValue);
}

gfc::engine::EntityRef NGfcRelAggregates::getRelatedObjects(int nIndex)
{
    return ((GfcRelAggregates*)m_pEntity)->getRelatedObjects(nIndex);
}


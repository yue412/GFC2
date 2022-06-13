#include "NGfcRelDefinesByProperties.h"

using namespace gfc::classes::x3;

NGfcRelDefinesByProperties::NGfcRelDefinesByProperties()
{
    m_pEntity = new GfcRelDefinesByProperties;
    m_bOwner = true;
}

NGfcRelDefinesByProperties::NGfcRelDefinesByProperties(bool bNoCreate):
    NGfcRelDefines(bNoCreate)
{
}

void NGfcRelDefinesByProperties::setRelatingPropertySet(gfc::engine::EntityRef nValue)
{
    ((GfcRelDefinesByProperties*)m_pEntity)->setRelatingPropertySet(nValue);
}

gfc::engine::EntityRef NGfcRelDefinesByProperties::getRelatingPropertySet()
{
    return ((GfcRelDefinesByProperties*)m_pEntity)->getRelatingPropertySet();
}

bool NGfcRelDefinesByProperties::hasRelatingPropertySet()
{
    return ((GfcRelDefinesByProperties*)m_pEntity)->hasRelatingPropertySet();
}

int NGfcRelDefinesByProperties::getRelatedObjectsCount()
{
    return ((GfcRelDefinesByProperties*)m_pEntity)->getRelatedObjectsCount();
}

void NGfcRelDefinesByProperties::clearRelatedObjects()
{
    ((GfcRelDefinesByProperties*)m_pEntity)->clearRelatedObjects();
}

void NGfcRelDefinesByProperties::addRelatedObjects(gfc::engine::EntityRef nValue)
{
    ((GfcRelDefinesByProperties*)m_pEntity)->addRelatedObjects(nValue);
}

gfc::engine::EntityRef NGfcRelDefinesByProperties::getRelatedObjects(int nIndex)
{
    return ((GfcRelDefinesByProperties*)m_pEntity)->getRelatedObjects(nIndex);
}


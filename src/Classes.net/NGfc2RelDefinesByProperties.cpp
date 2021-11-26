#include "NGfc2RelDefinesByProperties.h"

using namespace gfc::classes::x3;

NGfc2RelDefinesByProperties::NGfc2RelDefinesByProperties()
{
    m_pEntity = new Gfc2RelDefinesByProperties;
    m_bOwner = true;
}

NGfc2RelDefinesByProperties::NGfc2RelDefinesByProperties(void* pEntity, bool bOwner):
    NGfc2RelDefines(pEntity, bOwner)
{
}

void NGfc2RelDefinesByProperties::setRelatingPropertySet(gfc::engine::EntityRef nValue)
{
    ((Gfc2RelDefinesByProperties*)m_pEntity)->setRelatingPropertySet(nValue);
}

gfc::engine::EntityRef NGfc2RelDefinesByProperties::getRelatingPropertySet()
{
    return ((Gfc2RelDefinesByProperties*)m_pEntity)->getRelatingPropertySet();
}

bool NGfc2RelDefinesByProperties::hasRelatingPropertySet()
{
    return ((Gfc2RelDefinesByProperties*)m_pEntity)->hasRelatingPropertySet();
}

int NGfc2RelDefinesByProperties::getRelatedObjectsCount()
{
    return ((Gfc2RelDefinesByProperties*)m_pEntity)->getRelatedObjectsCount();
}

void NGfc2RelDefinesByProperties::clearRelatedObjects()
{
    ((Gfc2RelDefinesByProperties*)m_pEntity)->clearRelatedObjects();
}

void NGfc2RelDefinesByProperties::addRelatedObjects(gfc::engine::EntityRef nValue)
{
    ((Gfc2RelDefinesByProperties*)m_pEntity)->addRelatedObjects(nValue);
}

gfc::engine::EntityRef NGfc2RelDefinesByProperties::getRelatedObjects(int nIndex)
{
    return ((Gfc2RelDefinesByProperties*)m_pEntity)->getRelatedObjects(nIndex);
}


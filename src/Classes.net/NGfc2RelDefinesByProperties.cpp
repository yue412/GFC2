#include "StdAfx.h"
#include "NGfc2RelDefinesByProperties.h"
NGfc2RelDefinesByProperties::NGfc2RelDefinesByProperties()
{
    m_pEntity = new Gfc2RelDefinesByProperties;
    m_bOwner = true;
}

NGfc2RelDefinesByProperties::NGfc2RelDefinesByProperties(void* pEntity, bool bOwner):
    NGfc2RelDefines(pEntity, bOwner)
{
}

void NGfc2RelDefinesByProperties::setRelatingPropertySet(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RelDefinesByProperties*)m_pEntity)->setRelatingPropertySet(nValue);
}

glodon::objectbuf::EntityRef NGfc2RelDefinesByProperties::getRelatingPropertySet()
{
    return ((Gfc2RelDefinesByProperties*)m_pEntity)->getRelatingPropertySet();
}

bool NGfc2RelDefinesByProperties::hasRelatingPropertySet()
{
    return ((Gfc2RelDefinesByProperties*)m_pEntity)->hasRelatingPropertySet();
}

NGfc2PropertySet^ NGfc2RelDefinesByProperties::getRelatingPropertySetPtr()
{
    return gcnew NGfc2PropertySet(((Gfc2RelDefinesByProperties*)m_pEntity)->getRelatingPropertySetPtr(), false);
}

int NGfc2RelDefinesByProperties::getRelatedObjectsCount()
{
    return ((Gfc2RelDefinesByProperties*)m_pEntity)->getRelatedObjectsCount();
}

void NGfc2RelDefinesByProperties::clearRelatedObjects()
{
    ((Gfc2RelDefinesByProperties*)m_pEntity)->clearRelatedObjects();
}

void NGfc2RelDefinesByProperties::addRelatedObjects(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RelDefinesByProperties*)m_pEntity)->addRelatedObjects(nValue);
}

glodon::objectbuf::EntityRef NGfc2RelDefinesByProperties::getRelatedObjects(int nIndex)
{
    return ((Gfc2RelDefinesByProperties*)m_pEntity)->getRelatedObjects(nIndex);
}

NGfc2Object^ NGfc2RelDefinesByProperties::getRelatedObjectsPtr(int nIndex)
{
    return gcnew NGfc2Object(((Gfc2RelDefinesByProperties*)m_pEntity)->getRelatedObjectsPtr(nIndex), false);
}


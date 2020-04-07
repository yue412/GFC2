#include "StdAfx.h"
#include "NGfc2PropertySet.h"
NGfc2PropertySet::NGfc2PropertySet()
{
    m_pEntity = new Gfc2PropertySet;
    m_bOwner = true;
}

NGfc2PropertySet::NGfc2PropertySet(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

int NGfc2PropertySet::getHasPropertiesCount()
{
    return ((Gfc2PropertySet*)m_pEntity)->getHasPropertiesCount();
}

void NGfc2PropertySet::clearHasProperties()
{
    ((Gfc2PropertySet*)m_pEntity)->clearHasProperties();
}

void NGfc2PropertySet::addHasProperties(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2PropertySet*)m_pEntity)->addHasProperties(nValue);
}

glodon::objectbuf::EntityRef NGfc2PropertySet::getHasProperties(int nIndex)
{
    return ((Gfc2PropertySet*)m_pEntity)->getHasProperties(nIndex);
}

NGfc2Property^ NGfc2PropertySet::getHasPropertiesPtr(int nIndex)
{
    return gcnew NGfc2Property(((Gfc2PropertySet*)m_pEntity)->getHasPropertiesPtr(nIndex), false);
}


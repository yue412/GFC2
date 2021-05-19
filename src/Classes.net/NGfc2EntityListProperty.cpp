#include "StdAfx.h"
#include "NGfc2EntityListProperty.h"
NGfc2EntityListProperty::NGfc2EntityListProperty()
{
    m_pEntity = new Gfc2EntityListProperty;
    m_bOwner = true;
}

NGfc2EntityListProperty::NGfc2EntityListProperty(void* pEntity, bool bOwner):
    NGfc2ListProperty(pEntity, bOwner)
{
}

int NGfc2EntityListProperty::getValuesCount()
{
    return ((Gfc2EntityListProperty*)m_pEntity)->getValuesCount();
}

void NGfc2EntityListProperty::clearValues()
{
    ((Gfc2EntityListProperty*)m_pEntity)->clearValues();
}

void NGfc2EntityListProperty::addValues(gfc::engine::EntityRef nValue)
{
    ((Gfc2EntityListProperty*)m_pEntity)->addValues(nValue);
}

gfc::engine::EntityRef NGfc2EntityListProperty::getValues(int nIndex)
{
    return ((Gfc2EntityListProperty*)m_pEntity)->getValues(nIndex);
}

NGfc2Root^ NGfc2EntityListProperty::getValuesPtr(int nIndex)
{
    return gcnew NGfc2Root(((Gfc2EntityListProperty*)m_pEntity)->getValuesPtr(nIndex), false);
}


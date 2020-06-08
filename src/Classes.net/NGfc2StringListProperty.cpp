#include "StdAfx.h"
#include "NGfc2StringListProperty.h"
NGfc2StringListProperty::NGfc2StringListProperty()
{
    m_pEntity = new Gfc2StringListProperty;
    m_bOwner = true;
}

NGfc2StringListProperty::NGfc2StringListProperty(void* pEntity, bool bOwner):
    NGfc2ListProperty(pEntity, bOwner)
{
}

int NGfc2StringListProperty::getValuesCount()
{
    return ((Gfc2StringListProperty*)m_pEntity)->getValuesCount();
}

void NGfc2StringListProperty::clearValues()
{
    ((Gfc2StringListProperty*)m_pEntity)->clearValues();
}

void NGfc2StringListProperty::addValues(gfc::engine::EntityRef nValue)
{
    ((Gfc2StringListProperty*)m_pEntity)->addValues(nValue);
}

gfc::engine::EntityRef NGfc2StringListProperty::getValues(int nIndex)
{
    return ((Gfc2StringListProperty*)m_pEntity)->getValues(nIndex);
}

NGfc2String^ NGfc2StringListProperty::getValuesPtr(int nIndex)
{
    return gcnew NGfc2String(((Gfc2StringListProperty*)m_pEntity)->getValuesPtr(nIndex), false);
}


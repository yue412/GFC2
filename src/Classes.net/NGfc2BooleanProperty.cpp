#include "StdAfx.h"
#include "NGfc2BooleanProperty.h"
NGfc2BooleanProperty::NGfc2BooleanProperty()
{
    m_pEntity = new Gfc2BooleanProperty;
    m_bOwner = true;
}

NGfc2BooleanProperty::NGfc2BooleanProperty(void* pEntity, bool bOwner):
    NGfc2SingleProperty(pEntity, bOwner)
{
}

void NGfc2BooleanProperty::setValue(NGfc2Boolean bValue)
{
    ((Gfc2BooleanProperty*)m_pEntity)->setValue(bValue);
}

NGfc2Boolean NGfc2BooleanProperty::getValue()
{
    return ((Gfc2BooleanProperty*)m_pEntity)->getValue();
}

bool NGfc2BooleanProperty::hasValue()
{
    return ((Gfc2BooleanProperty*)m_pEntity)->hasValue();
}


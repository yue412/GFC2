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

void NGfc2BooleanProperty::setVal(NGfc2Boolean bValue)
{
    ((Gfc2BooleanProperty*)m_pEntity)->setVal(bValue);
}

NGfc2Boolean NGfc2BooleanProperty::getVal()
{
    return ((Gfc2BooleanProperty*)m_pEntity)->getVal();
}

bool NGfc2BooleanProperty::hasVal()
{
    return ((Gfc2BooleanProperty*)m_pEntity)->hasVal();
}


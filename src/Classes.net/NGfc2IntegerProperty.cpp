#include "StdAfx.h"
#include "NGfc2IntegerProperty.h"
NGfc2IntegerProperty::NGfc2IntegerProperty()
{
    m_pEntity = new Gfc2IntegerProperty;
    m_bOwner = true;
}

NGfc2IntegerProperty::NGfc2IntegerProperty(void* pEntity, bool bOwner):
    NGfc2Property(pEntity, bOwner)
{
}

void NGfc2IntegerProperty::setValue(NGfc2Integer nValue)
{
    ((Gfc2IntegerProperty*)m_pEntity)->setValue(nValue);
}

NGfc2Integer NGfc2IntegerProperty::getValue()
{
    return ((Gfc2IntegerProperty*)m_pEntity)->getValue();
}

bool NGfc2IntegerProperty::hasValue()
{
    return ((Gfc2IntegerProperty*)m_pEntity)->hasValue();
}


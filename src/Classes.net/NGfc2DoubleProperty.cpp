#include "StdAfx.h"
#include "NGfc2DoubleProperty.h"
NGfc2DoubleProperty::NGfc2DoubleProperty()
{
    m_pEntity = new Gfc2DoubleProperty;
    m_bOwner = true;
}

NGfc2DoubleProperty::NGfc2DoubleProperty(void* pEntity, bool bOwner):
    NGfc2Property(pEntity, bOwner)
{
}

void NGfc2DoubleProperty::setValue(NGfc2Double dValue)
{
    ((Gfc2DoubleProperty*)m_pEntity)->setValue(dValue);
}

NGfc2Double NGfc2DoubleProperty::getValue()
{
    return ((Gfc2DoubleProperty*)m_pEntity)->getValue();
}

bool NGfc2DoubleProperty::hasValue()
{
    return ((Gfc2DoubleProperty*)m_pEntity)->hasValue();
}


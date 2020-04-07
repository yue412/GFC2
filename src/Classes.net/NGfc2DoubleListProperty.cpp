#include "StdAfx.h"
#include "NGfc2DoubleListProperty.h"
NGfc2DoubleListProperty::NGfc2DoubleListProperty()
{
    m_pEntity = new Gfc2DoubleListProperty;
    m_bOwner = true;
}

NGfc2DoubleListProperty::NGfc2DoubleListProperty(void* pEntity, bool bOwner):
    NGfc2ListProperty(pEntity, bOwner)
{
}

int NGfc2DoubleListProperty::getValuesCount()
{
    return ((Gfc2DoubleListProperty*)m_pEntity)->getValuesCount();
}

void NGfc2DoubleListProperty::clearValues()
{
    ((Gfc2DoubleListProperty*)m_pEntity)->clearValues();
}

void NGfc2DoubleListProperty::addValues(NGfc2Double dValue)
{
    ((Gfc2DoubleListProperty*)m_pEntity)->addValues(dValue);
}

NGfc2Double NGfc2DoubleListProperty::getValues(int nIndex)
{
    return ((Gfc2DoubleListProperty*)m_pEntity)->getValues(nIndex);
}


#include "StdAfx.h"
#include "NGfc2DoubleProperty.h"
NGfc2DoubleProperty::NGfc2DoubleProperty()
{
    m_pEntity = new Gfc2DoubleProperty;
    m_bOwner = true;
}

NGfc2DoubleProperty::NGfc2DoubleProperty(void* pEntity, bool bOwner):
    NGfc2SingleProperty(pEntity, bOwner)
{
}

void NGfc2DoubleProperty::setVal(NGfc2Double dValue)
{
    ((Gfc2DoubleProperty*)m_pEntity)->setVal(dValue);
}

NGfc2Double NGfc2DoubleProperty::getVal()
{
    return ((Gfc2DoubleProperty*)m_pEntity)->getVal();
}

bool NGfc2DoubleProperty::hasVal()
{
    return ((Gfc2DoubleProperty*)m_pEntity)->hasVal();
}


#include "NGfc2IntegerListProperty.h"

using namespace gfc::classes::x3;

NGfc2IntegerListProperty::NGfc2IntegerListProperty()
{
    m_pEntity = new Gfc2IntegerListProperty;
    m_bOwner = true;
}

NGfc2IntegerListProperty::NGfc2IntegerListProperty(void* pEntity, bool bOwner):
    NGfc2ListProperty(pEntity, bOwner)
{
}

int NGfc2IntegerListProperty::getValuesCount()
{
    return ((Gfc2IntegerListProperty*)m_pEntity)->getValuesCount();
}

void NGfc2IntegerListProperty::clearValues()
{
    ((Gfc2IntegerListProperty*)m_pEntity)->clearValues();
}

void NGfc2IntegerListProperty::addValues(NGfc2Integer nValue)
{
    ((Gfc2IntegerListProperty*)m_pEntity)->addValues(nValue);
}

NGfc2Integer NGfc2IntegerListProperty::getValues(int nIndex)
{
    return ((Gfc2IntegerListProperty*)m_pEntity)->getValues(nIndex);
}


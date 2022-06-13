#include "NGfcIntegerListProperty.h"

using namespace gfc::classes::x3;

NGfcIntegerListProperty::NGfcIntegerListProperty()
{
    m_pEntity = new GfcIntegerListProperty;
    m_bOwner = true;
}

NGfcIntegerListProperty::NGfcIntegerListProperty(bool bNoCreate):
    NGfcListProperty(bNoCreate)
{
}

int NGfcIntegerListProperty::getValuesCount()
{
    return ((GfcIntegerListProperty*)m_pEntity)->getValuesCount();
}

void NGfcIntegerListProperty::clearValues()
{
    ((GfcIntegerListProperty*)m_pEntity)->clearValues();
}

void NGfcIntegerListProperty::addValues(NGfcInteger nValue)
{
    ((GfcIntegerListProperty*)m_pEntity)->addValues(nValue);
}

NGfcInteger NGfcIntegerListProperty::getValues(int nIndex)
{
    return ((GfcIntegerListProperty*)m_pEntity)->getValues(nIndex);
}


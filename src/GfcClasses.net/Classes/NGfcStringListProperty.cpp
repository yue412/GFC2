#include "NGfcStringListProperty.h"

using namespace gfc::classes::x3;

NGfcStringListProperty::NGfcStringListProperty()
{
    m_pEntity = new GfcStringListProperty;
    m_bOwner = true;
}

NGfcStringListProperty::NGfcStringListProperty(bool bNoCreate):
    NGfcListProperty(bNoCreate)
{
}

int NGfcStringListProperty::getValuesCount()
{
    return ((GfcStringListProperty*)m_pEntity)->getValuesCount();
}

void NGfcStringListProperty::clearValues()
{
    ((GfcStringListProperty*)m_pEntity)->clearValues();
}

void NGfcStringListProperty::addValues(NGfcString sValue)
{
    ((GfcStringListProperty*)m_pEntity)->addValues(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcStringListProperty::getValues(int nIndex)
{
    return marshal_as<String^>(((GfcStringListProperty*)m_pEntity)->getValues(nIndex));
}


#include "NGfcStringProperty.h"

using namespace gfc::classes::x3;

NGfcStringProperty::NGfcStringProperty()
{
    m_pEntity = new GfcStringProperty;
    m_bOwner = true;
}

NGfcStringProperty::NGfcStringProperty(bool bNoCreate):
    NGfcSingleProperty(bNoCreate)
{
}

void NGfcStringProperty::setVal(NGfcString sValue)
{
    ((GfcStringProperty*)m_pEntity)->setVal(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcStringProperty::getVal()
{
    return marshal_as<String^>(((GfcStringProperty*)m_pEntity)->getVal());
}

bool NGfcStringProperty::hasVal()
{
    return ((GfcStringProperty*)m_pEntity)->hasVal();
}


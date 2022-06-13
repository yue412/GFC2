#include "NGfcDoubleProperty.h"

using namespace gfc::classes::x3;

NGfcDoubleProperty::NGfcDoubleProperty()
{
    m_pEntity = new GfcDoubleProperty;
    m_bOwner = true;
}

NGfcDoubleProperty::NGfcDoubleProperty(bool bNoCreate):
    NGfcSingleProperty(bNoCreate)
{
}

void NGfcDoubleProperty::setVal(NGfcDouble dValue)
{
    ((GfcDoubleProperty*)m_pEntity)->setVal(dValue);
}

NGfcDouble NGfcDoubleProperty::getVal()
{
    return ((GfcDoubleProperty*)m_pEntity)->getVal();
}

bool NGfcDoubleProperty::hasVal()
{
    return ((GfcDoubleProperty*)m_pEntity)->hasVal();
}


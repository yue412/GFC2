#include "NGfcDoubleListProperty.h"

using namespace gfc::classes::x3;

NGfcDoubleListProperty::NGfcDoubleListProperty()
{
    m_pEntity = new GfcDoubleListProperty;
    m_bOwner = true;
}

NGfcDoubleListProperty::NGfcDoubleListProperty(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcListProperty(pEntity, bOwner)
{
}

int NGfcDoubleListProperty::getValuesCount()
{
    return ((GfcDoubleListProperty*)m_pEntity)->getValuesCount();
}

void NGfcDoubleListProperty::clearValues()
{
    ((GfcDoubleListProperty*)m_pEntity)->clearValues();
}

void NGfcDoubleListProperty::addValues(NGfcDouble dValue)
{
    ((GfcDoubleListProperty*)m_pEntity)->addValues(dValue);
}

NGfcDouble NGfcDoubleListProperty::getValues(int nIndex)
{
    return ((GfcDoubleListProperty*)m_pEntity)->getValues(nIndex);
}


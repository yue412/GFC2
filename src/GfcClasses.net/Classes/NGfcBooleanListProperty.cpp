#include "NGfcBooleanListProperty.h"

using namespace gfc::classes::x3;

NGfcBooleanListProperty::NGfcBooleanListProperty()
{
    m_pEntity = new GfcBooleanListProperty;
    m_bOwner = true;
}

NGfcBooleanListProperty::NGfcBooleanListProperty(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcListProperty(pEntity, bOwner)
{
}

int NGfcBooleanListProperty::getValuesCount()
{
    return ((GfcBooleanListProperty*)m_pEntity)->getValuesCount();
}

void NGfcBooleanListProperty::clearValues()
{
    ((GfcBooleanListProperty*)m_pEntity)->clearValues();
}

void NGfcBooleanListProperty::addValues(NGfcBoolean bValue)
{
    ((GfcBooleanListProperty*)m_pEntity)->addValues(bValue);
}

NGfcBoolean NGfcBooleanListProperty::getValues(int nIndex)
{
    return ((GfcBooleanListProperty*)m_pEntity)->getValues(nIndex);
}


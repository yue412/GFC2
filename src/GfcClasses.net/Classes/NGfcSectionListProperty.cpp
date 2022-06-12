#include "NGfcSectionListProperty.h"

using namespace gfc::classes::x3;

NGfcSectionListProperty::NGfcSectionListProperty()
{
    m_pEntity = new GfcSectionListProperty;
    m_bOwner = true;
}

NGfcSectionListProperty::NGfcSectionListProperty(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcListProperty(pEntity, bOwner)
{
}

int NGfcSectionListProperty::getValuesCount()
{
    return ((GfcSectionListProperty*)m_pEntity)->getValuesCount();
}

void NGfcSectionListProperty::clearValues()
{
    ((GfcSectionListProperty*)m_pEntity)->clearValues();
}

void NGfcSectionListProperty::addValues(gfc::engine::EntityRef nValue)
{
    ((GfcSectionListProperty*)m_pEntity)->addValues(nValue);
}

gfc::engine::EntityRef NGfcSectionListProperty::getValues(int nIndex)
{
    return ((GfcSectionListProperty*)m_pEntity)->getValues(nIndex);
}


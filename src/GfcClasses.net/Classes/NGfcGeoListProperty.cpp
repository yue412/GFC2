#include "NGfcGeoListProperty.h"

using namespace gfc::classes::x3;

NGfcGeoListProperty::NGfcGeoListProperty()
{
    m_pEntity = new GfcGeoListProperty;
    m_bOwner = true;
}

NGfcGeoListProperty::NGfcGeoListProperty(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcListProperty(pEntity, bOwner)
{
}

int NGfcGeoListProperty::getValuesCount()
{
    return ((GfcGeoListProperty*)m_pEntity)->getValuesCount();
}

void NGfcGeoListProperty::clearValues()
{
    ((GfcGeoListProperty*)m_pEntity)->clearValues();
}

void NGfcGeoListProperty::addValues(gfc::engine::EntityRef nValue)
{
    ((GfcGeoListProperty*)m_pEntity)->addValues(nValue);
}

gfc::engine::EntityRef NGfcGeoListProperty::getValues(int nIndex)
{
    return ((GfcGeoListProperty*)m_pEntity)->getValues(nIndex);
}


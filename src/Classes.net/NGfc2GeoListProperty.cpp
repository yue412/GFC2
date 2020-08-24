#include "StdAfx.h"
#include "NGfc2GeoListProperty.h"
NGfc2GeoListProperty::NGfc2GeoListProperty()
{
    m_pEntity = new Gfc2GeoListProperty;
    m_bOwner = true;
}

NGfc2GeoListProperty::NGfc2GeoListProperty(void* pEntity, bool bOwner):
    NGfc2ListProperty(pEntity, bOwner)
{
}

int NGfc2GeoListProperty::getValuesCount()
{
    return ((Gfc2GeoListProperty*)m_pEntity)->getValuesCount();
}

void NGfc2GeoListProperty::clearValues()
{
    ((Gfc2GeoListProperty*)m_pEntity)->clearValues();
}

void NGfc2GeoListProperty::addValues(gfc::engine::EntityRef nValue)
{
    ((Gfc2GeoListProperty*)m_pEntity)->addValues(nValue);
}

gfc::engine::EntityRef NGfc2GeoListProperty::getValues(int nIndex)
{
    return ((Gfc2GeoListProperty*)m_pEntity)->getValues(nIndex);
}

NGfc2Geometry^ NGfc2GeoListProperty::getValuesPtr(int nIndex)
{
    return gcnew NGfc2Geometry(((Gfc2GeoListProperty*)m_pEntity)->getValuesPtr(nIndex), false);
}


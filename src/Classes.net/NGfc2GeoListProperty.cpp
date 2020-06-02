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

int NGfc2GeoListProperty::getValueCount()
{
    return ((Gfc2GeoListProperty*)m_pEntity)->getValueCount();
}

void NGfc2GeoListProperty::clearValue()
{
    ((Gfc2GeoListProperty*)m_pEntity)->clearValue();
}

void NGfc2GeoListProperty::addValue(gfc2::engine::EntityRef nValue)
{
    ((Gfc2GeoListProperty*)m_pEntity)->addValue(nValue);
}

gfc2::engine::EntityRef NGfc2GeoListProperty::getValue(int nIndex)
{
    return ((Gfc2GeoListProperty*)m_pEntity)->getValue(nIndex);
}

NGfc2Geometry^ NGfc2GeoListProperty::getValuePtr(int nIndex)
{
    return gcnew NGfc2Geometry(((Gfc2GeoListProperty*)m_pEntity)->getValuePtr(nIndex), false);
}


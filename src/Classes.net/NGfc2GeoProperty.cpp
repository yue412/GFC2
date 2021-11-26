#include "NGfc2GeoProperty.h"

using namespace gfc::classes::x3;

NGfc2GeoProperty::NGfc2GeoProperty()
{
    m_pEntity = new Gfc2GeoProperty;
    m_bOwner = true;
}

NGfc2GeoProperty::NGfc2GeoProperty(void* pEntity, bool bOwner):
    NGfc2SingleProperty(pEntity, bOwner)
{
}

void NGfc2GeoProperty::setGeo(gfc::engine::EntityRef nValue)
{
    ((Gfc2GeoProperty*)m_pEntity)->setGeo(nValue);
}

gfc::engine::EntityRef NGfc2GeoProperty::getGeo()
{
    return ((Gfc2GeoProperty*)m_pEntity)->getGeo();
}

bool NGfc2GeoProperty::hasGeo()
{
    return ((Gfc2GeoProperty*)m_pEntity)->hasGeo();
}


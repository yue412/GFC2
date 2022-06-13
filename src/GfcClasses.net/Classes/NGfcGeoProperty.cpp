#include "NGfcGeoProperty.h"

using namespace gfc::classes::x3;

NGfcGeoProperty::NGfcGeoProperty()
{
    m_pEntity = new GfcGeoProperty;
    m_bOwner = true;
}

NGfcGeoProperty::NGfcGeoProperty(bool bNoCreate):
    NGfcSingleProperty(bNoCreate)
{
}

void NGfcGeoProperty::setGeo(gfc::engine::EntityRef nValue)
{
    ((GfcGeoProperty*)m_pEntity)->setGeo(nValue);
}

gfc::engine::EntityRef NGfcGeoProperty::getGeo()
{
    return ((GfcGeoProperty*)m_pEntity)->getGeo();
}

bool NGfcGeoProperty::hasGeo()
{
    return ((GfcGeoProperty*)m_pEntity)->hasGeo();
}


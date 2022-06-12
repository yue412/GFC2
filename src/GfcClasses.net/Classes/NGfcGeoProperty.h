#ifndef NGFCGEOPROPERTY_H
#define NGFCGEOPROPERTY_H

#include "NGfcSingleProperty.h"
#include "GfcClasses\x3\GfcGeoProperty.h"
#include "NGfcGeometry.h"

public ref class NGfcGeoProperty: public NGfcSingleProperty
{
public:
    NGfcGeoProperty();
    NGfcGeoProperty(gfc::engine::CEntity* pEntity, bool bOwner);
    void setGeo(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getGeo();
    bool hasGeo();

};
#endif

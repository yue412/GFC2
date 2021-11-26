#ifndef NGFC2GEOPROPERTY_H
#define NGFC2GEOPROPERTY_H

#include "NGfc2SingleProperty.h"
#include "GfcClasses\x3\Gfc2GeoProperty.h"
#include "NGfc2Geometry.h"

public ref class NGfc2GeoProperty: public NGfc2SingleProperty
{
public:
    NGfc2GeoProperty();
    NGfc2GeoProperty(gfc::engine::CEntity* pEntity, bool bOwner);
    void setGeo(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getGeo();
    bool hasGeo();

};
#endif

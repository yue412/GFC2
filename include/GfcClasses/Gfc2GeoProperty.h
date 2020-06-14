#ifndef GFC2GEOPROPERTY_H
#define GFC2GEOPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2SingleProperty.h"
#include "Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2GeoProperty: public Gfc2SingleProperty
{
GFCENGINE_DEC_OBJECT(Gfc2GeoProperty, gfc::engine::CEntity)
public:
    Gfc2GeoProperty();
    Gfc2GeoProperty(bool bSetSchema);
    void setGeo(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getGeo() const;
    bool hasGeo() const;
    gfc::engine::CEntityWrapPtr<Gfc2Geometry> getGeoPtr();

};
#endif

#ifndef GFC2GEOPROPERTY_H
#define GFC2GEOPROPERTY_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2SingleProperty.h"
#include "Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2GeoProperty: public Gfc2SingleProperty
{
GFCENGINE_DEC_OBJECT(Gfc2GeoProperty,gfc2::engine::EntityFactory)
public:
    Gfc2GeoProperty();
    Gfc2GeoProperty(bool bSetSchema);
    void setGeo(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getGeo() const;
    bool hasGeo() const;
    std::shared_ptr<Gfc2Geometry> getGeoPtr();

};
#endif

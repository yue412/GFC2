#ifndef GFC2GEOPROPERTY_H
#define GFC2GEOPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2SingleProperty.h"
#include "GfcClasses/x3/Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

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

GFCCLASSES_NAMESPACE_END

#endif

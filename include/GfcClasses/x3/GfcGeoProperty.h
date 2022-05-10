#ifndef GFCGEOPROPERTY_H
#define GFCGEOPROPERTY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcSingleProperty.h"
#include "GfcClasses/x3/GfcGeometry.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcGeoProperty: public GfcSingleProperty
{
GFCENGINE_DEC_OBJECT(GfcGeoProperty, gfc::engine::CEntity)
public:
    GfcGeoProperty();
    GfcGeoProperty(bool bSetSchema);
    void setGeo(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getGeo() const;
    bool hasGeo() const;
    std::shared_ptr<GfcGeometry> getGeoPtr();

};

GFCCLASSES_NAMESPACE_END

#endif

#ifndef GFC2GEOLISTPROPERTY_H
#define GFC2GEOLISTPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2ListProperty.h"
#include "Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2GeoListProperty: public Gfc2ListProperty
{
GFCENGINE_DEC_OBJECT(Gfc2GeoListProperty, gfc2::engine::Entity)
public:
    Gfc2GeoListProperty();
    Gfc2GeoListProperty(bool bSetSchema);
    int getValueCount() const;
    void clearValue();
    void addValue(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getValue(int nIndex) const;
    std::shared_ptr<Gfc2Geometry> getValuePtr(int nIndex);

};
#endif

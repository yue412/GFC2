#ifndef GFC2GEOLISTPROPERTY_H
#define GFC2GEOLISTPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2ListProperty.h"
#include "Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2GeoListProperty: public Gfc2ListProperty
{
GFCENGINE_DEC_OBJECT(Gfc2GeoListProperty, gfc::engine::CEntity)
public:
    Gfc2GeoListProperty();
    Gfc2GeoListProperty(bool bSetSchema);
    int getValueCount() const;
    void clearValue();
    void addValue(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getValue(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Geometry> getValuePtr(int nIndex);

};
#endif

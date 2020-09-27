#ifndef GFC2GEOLISTPROPERTY_H
#define GFC2GEOLISTPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2ListProperty.h"
#include "GfcClasses/x3/Gfc2Geometry.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2GeoListProperty: public Gfc2ListProperty
{
GFCENGINE_DEC_OBJECT(Gfc2GeoListProperty, gfc::engine::CEntity)
public:
    Gfc2GeoListProperty();
    Gfc2GeoListProperty(bool bSetSchema);
    int getValuesCount() const;
    void clearValues();
    void addValues(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getValues(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Geometry> getValuesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif

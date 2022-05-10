#ifndef GFCGEOLISTPROPERTY_H
#define GFCGEOLISTPROPERTY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcListProperty.h"
#include "GfcClasses/x3/GfcGeometry.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcGeoListProperty: public GfcListProperty
{
GFCENGINE_DEC_OBJECT(GfcGeoListProperty, gfc::engine::CEntity)
public:
    GfcGeoListProperty();
    GfcGeoListProperty(bool bSetSchema);
    int getValuesCount() const;
    void clearValues();
    void addValues(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getValues(int nIndex) const;
    std::shared_ptr<GfcGeometry> getValuesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif

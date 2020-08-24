#ifndef NGFC2GEOLISTPROPERTY_H
#define NGFC2GEOLISTPROPERTY_H

#include "NGfc2ListProperty.h"
#include "Gfc2GeoListProperty.h"
#include "NGfc2Geometry.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2GeoListProperty: public NGfc2ListProperty
{
public:
    NGfc2GeoListProperty();
    NGfc2GeoListProperty(void* pEntity, bool bOwner);
    int getValuesCount();
    void clearValues();
    void addValues(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getValues(int nIndex);
    NGfc2Geometry^ getValuesPtr(int nIndex);

};
#endif

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
    int getValueCount();
    void clearValue();
    void addValue(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getValue(int nIndex);
    NGfc2Geometry^ getValuePtr(int nIndex);

};
#endif

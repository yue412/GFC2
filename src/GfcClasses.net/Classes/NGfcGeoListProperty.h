#ifndef NGFCGEOLISTPROPERTY_H
#define NGFCGEOLISTPROPERTY_H

#include "NGfcListProperty.h"
#include "GfcClasses\x3\GfcGeoListProperty.h"
#include "NGfcGeometry.h"

public ref class NGfcGeoListProperty: public NGfcListProperty
{
public:
    NGfcGeoListProperty();
    NGfcGeoListProperty(gfc::engine::CEntity* pEntity, bool bOwner);
    int getValuesCount();
    void clearValues();
    void addValues(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getValues(int nIndex);

};
#endif

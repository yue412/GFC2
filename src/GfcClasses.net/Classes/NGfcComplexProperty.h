#ifndef NGFCCOMPLEXPROPERTY_H
#define NGFCCOMPLEXPROPERTY_H

#include "NGfcProperty.h"
#include "GfcClasses\x3\GfcComplexProperty.h"

public ref class NGfcComplexProperty: public NGfcProperty
{
public:
    NGfcComplexProperty();
    NGfcComplexProperty(bool bNoCreate);
    int getHasPropertiesCount();
    void clearHasProperties();
    void addHasProperties(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getHasProperties(int nIndex);

};
#endif

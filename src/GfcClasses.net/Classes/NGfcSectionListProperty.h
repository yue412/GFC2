#ifndef NGFCSECTIONLISTPROPERTY_H
#define NGFCSECTIONLISTPROPERTY_H

#include "NGfcListProperty.h"
#include "GfcClasses\x3\GfcSectionListProperty.h"
#include "NGfcSection.h"

public ref class NGfcSectionListProperty: public NGfcListProperty
{
public:
    NGfcSectionListProperty();
    NGfcSectionListProperty(bool bNoCreate);
    int getValuesCount();
    void clearValues();
    void addValues(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getValues(int nIndex);

};
#endif

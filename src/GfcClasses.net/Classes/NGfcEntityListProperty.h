#ifndef NGFCENTITYLISTPROPERTY_H
#define NGFCENTITYLISTPROPERTY_H

#include "NGfcListProperty.h"
#include "GfcClasses\x3\GfcEntityListProperty.h"
#include "NGfcRoot.h"

public ref class NGfcEntityListProperty: public NGfcListProperty
{
public:
    NGfcEntityListProperty();
    NGfcEntityListProperty(gfc::engine::CEntity* pEntity, bool bOwner);
    int getValuesCount();
    void clearValues();
    void addValues(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getValues(int nIndex);

};
#endif

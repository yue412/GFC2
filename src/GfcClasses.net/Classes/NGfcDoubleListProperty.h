#ifndef NGFCDOUBLELISTPROPERTY_H
#define NGFCDOUBLELISTPROPERTY_H

#include "NGfcListProperty.h"
#include "GfcClasses\x3\GfcDoubleListProperty.h"
#include "NTypeDef.h"

public ref class NGfcDoubleListProperty: public NGfcListProperty
{
public:
    NGfcDoubleListProperty();
    NGfcDoubleListProperty(gfc::engine::CEntity* pEntity, bool bOwner);
    int getValuesCount();
    void clearValues();
    void addValues(NGfcDouble dValue);
    NGfcDouble getValues(int nIndex);

};
#endif

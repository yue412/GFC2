#ifndef NGFCDOUBLEPROPERTY_H
#define NGFCDOUBLEPROPERTY_H

#include "NGfcSingleProperty.h"
#include "GfcClasses\x3\GfcDoubleProperty.h"
#include "NTypeDef.h"

public ref class NGfcDoubleProperty: public NGfcSingleProperty
{
public:
    NGfcDoubleProperty();
    NGfcDoubleProperty(gfc::engine::CEntity* pEntity, bool bOwner);
    void setVal(NGfcDouble dValue);
    NGfcDouble getVal();
    bool hasVal();

};
#endif

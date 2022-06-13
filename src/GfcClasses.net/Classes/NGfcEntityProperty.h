#ifndef NGFCENTITYPROPERTY_H
#define NGFCENTITYPROPERTY_H

#include "NGfcSingleProperty.h"
#include "GfcClasses\x3\GfcEntityProperty.h"
#include "NGfcRoot.h"

public ref class NGfcEntityProperty: public NGfcSingleProperty
{
public:
    NGfcEntityProperty();
    NGfcEntityProperty(bool bNoCreate);
    void setVal(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getVal();
    bool hasVal();

};
#endif

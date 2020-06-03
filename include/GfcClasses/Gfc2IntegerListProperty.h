#ifndef GFC2INTEGERLISTPROPERTY_H
#define GFC2INTEGERLISTPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2ListProperty.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2IntegerListProperty: public Gfc2ListProperty
{
GFCENGINE_DEC_OBJECT(Gfc2IntegerListProperty, gfc2::engine::Entity)
public:
    Gfc2IntegerListProperty();
    Gfc2IntegerListProperty(bool bSetSchema);
    int getValuesCount() const;
    void clearValues();
    void addValues(const Gfc2Integer& nValue);
    Gfc2Integer getValues(int nIndex) const;

};
#endif

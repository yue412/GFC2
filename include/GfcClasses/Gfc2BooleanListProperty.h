#ifndef GFC2BOOLEANLISTPROPERTY_H
#define GFC2BOOLEANLISTPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2ListProperty.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2BooleanListProperty: public Gfc2ListProperty
{
GFCENGINE_DEC_OBJECT(Gfc2BooleanListProperty, gfc::engine::CEntity)
public:
    Gfc2BooleanListProperty();
    Gfc2BooleanListProperty(bool bSetSchema);
    int getValuesCount() const;
    void clearValues();
    void addValues(const Gfc2Boolean& bValue);
    Gfc2Boolean getValues(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif

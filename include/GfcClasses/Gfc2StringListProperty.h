#ifndef GFC2STRINGLISTPROPERTY_H
#define GFC2STRINGLISTPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2ListProperty.h"
#include "Gfc2String.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2StringListProperty: public Gfc2ListProperty
{
GFCENGINE_DEC_OBJECT(Gfc2StringListProperty, gfc::engine::CEntity)
public:
    Gfc2StringListProperty();
    Gfc2StringListProperty(bool bSetSchema);
    int getValuesCount() const;
    void clearValues();
    void addValues(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getValues(int nIndex) const;
    std::shared_ptr<Gfc2String> getValuesPtr(int nIndex);

};
#endif

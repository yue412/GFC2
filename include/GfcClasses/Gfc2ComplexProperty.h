#ifndef GFC2COMPLEXPROPERTY_H
#define GFC2COMPLEXPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2Property.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ComplexProperty: public Gfc2Property
{
GFCENGINE_DEC_OBJECT(Gfc2ComplexProperty, gfc::engine::CEntity)
public:
    Gfc2ComplexProperty();
    Gfc2ComplexProperty(bool bSetSchema);
    int getHasPropertiesCount() const;
    void clearHasProperties();
    void addHasProperties(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getHasProperties(int nIndex) const;
    std::shared_ptr<Gfc2Property> getHasPropertiesPtr(int nIndex);

};
#endif

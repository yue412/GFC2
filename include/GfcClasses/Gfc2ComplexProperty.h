#ifndef GFC2COMPLEXPROPERTY_H
#define GFC2COMPLEXPROPERTY_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Property.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ComplexProperty: public Gfc2Property
{
GFCENGINE_DEC_OBJECT(Gfc2ComplexProperty,gfc2::engine::EntityFactory)
public:
    Gfc2ComplexProperty();
    Gfc2ComplexProperty(bool bSetSchema);
    int getHasPropertiesCount() const;
    void clearHasProperties();
    void addHasProperties(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getHasProperties(int nIndex) const;
    std::shared_ptr<Gfc2Property> getHasPropertiesPtr(int nIndex);

};
#endif

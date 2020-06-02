#ifndef GFC2PROPERTYSET_H
#define GFC2PROPERTYSET_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Property.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2PropertySet: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2PropertySet,gfc2::engine::EntityFactory)
public:
    Gfc2PropertySet();
    Gfc2PropertySet(bool bSetSchema);
    int getHasPropertiesCount() const;
    void clearHasProperties();
    void addHasProperties(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getHasProperties(int nIndex) const;
    std::shared_ptr<Gfc2Property> getHasPropertiesPtr(int nIndex);

};
#endif

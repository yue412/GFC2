#ifndef GFC2PROPERTYSET_H
#define GFC2PROPERTYSET_H

#include "GfcClasses.h"
#include "Gfc2Property.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2PropertySet: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2PropertySet, gfc::engine::CEntity)
public:
    Gfc2PropertySet();
    Gfc2PropertySet(bool bSetSchema);
    void setName(const Gfc2Label& sValue);
    Gfc2Label getName() const;
    bool hasName() const;
    int getHasPropertiesCount() const;
    void clearHasProperties();
    void addHasProperties(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getHasProperties(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Property> getHasPropertiesPtr(int nIndex);

};
#endif

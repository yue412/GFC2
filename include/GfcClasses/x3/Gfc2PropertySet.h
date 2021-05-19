#ifndef GFC2PROPERTYSET_H
#define GFC2PROPERTYSET_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Root.h"
#include "GfcClasses/x3/Gfc2Property.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2PropertySet: public Gfc2Root
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
    std::shared_ptr<Gfc2Property> getHasPropertiesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif

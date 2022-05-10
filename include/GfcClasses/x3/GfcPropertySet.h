#ifndef GFCPROPERTYSET_H
#define GFCPROPERTYSET_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcProperty.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPropertySet: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcPropertySet, gfc::engine::CEntity)
public:
    GfcPropertySet();
    GfcPropertySet(bool bSetSchema);
    void setName(const GfcLabel& sValue);
    GfcLabel getName() const;
    bool hasName() const;
    int getHasPropertiesCount() const;
    void clearHasProperties();
    void addHasProperties(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getHasProperties(int nIndex) const;
    std::shared_ptr<GfcProperty> getHasPropertiesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif

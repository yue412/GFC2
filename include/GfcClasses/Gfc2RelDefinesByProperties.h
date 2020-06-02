#ifndef GFC2RELDEFINESBYPROPERTIES_H
#define GFC2RELDEFINESBYPROPERTIES_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2RelDefines.h"
#include "Gfc2PropertySet.h"
#include "Gfc2Object.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelDefinesByProperties: public Gfc2RelDefines
{
GFCENGINE_DEC_OBJECT(Gfc2RelDefinesByProperties,gfc2::engine::EntityFactory)
public:
    Gfc2RelDefinesByProperties();
    Gfc2RelDefinesByProperties(bool bSetSchema);
    void setRelatingPropertySet(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRelatingPropertySet() const;
    bool hasRelatingPropertySet() const;
    std::shared_ptr<Gfc2PropertySet> getRelatingPropertySetPtr();
    int getRelatedObjectsCount() const;
    void clearRelatedObjects();
    void addRelatedObjects(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRelatedObjects(int nIndex) const;
    std::shared_ptr<Gfc2Object> getRelatedObjectsPtr(int nIndex);

};
#endif

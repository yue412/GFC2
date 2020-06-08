#ifndef GFC2RELDEFINESBYPROPERTIES_H
#define GFC2RELDEFINESBYPROPERTIES_H

#include "GfcClasses.h"
#include "Gfc2RelDefines.h"
#include "Gfc2PropertySet.h"
#include "Gfc2Object.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelDefinesByProperties: public Gfc2RelDefines
{
GFCENGINE_DEC_OBJECT(Gfc2RelDefinesByProperties, gfc::engine::CEntity)
public:
    Gfc2RelDefinesByProperties();
    Gfc2RelDefinesByProperties(bool bSetSchema);
    void setRelatingPropertySet(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingPropertySet() const;
    bool hasRelatingPropertySet() const;
    std::shared_ptr<Gfc2PropertySet> getRelatingPropertySetPtr();
    int getRelatedObjectsCount() const;
    void clearRelatedObjects();
    void addRelatedObjects(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatedObjects(int nIndex) const;
    std::shared_ptr<Gfc2Object> getRelatedObjectsPtr(int nIndex);

};
#endif

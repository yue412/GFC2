#ifndef GFC2RELDEFINESBYPROPERTIES_H
#define GFC2RELDEFINESBYPROPERTIES_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2RelDefines.h"
#include "GfcClasses/x3/Gfc2PropertySet.h"
#include "GfcClasses/x3/Gfc2Object.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RelDefinesByProperties: public Gfc2RelDefines
{
GFCENGINE_DEC_OBJECT(Gfc2RelDefinesByProperties, gfc::engine::CEntity)
public:
    Gfc2RelDefinesByProperties();
    Gfc2RelDefinesByProperties(bool bSetSchema);
    void setRelatingPropertySet(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingPropertySet() const;
    bool hasRelatingPropertySet() const;
    gfc::engine::CEntityWrapPtr<Gfc2PropertySet> getRelatingPropertySetPtr();
    int getRelatedObjectsCount() const;
    void clearRelatedObjects();
    void addRelatedObjects(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatedObjects(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Object> getRelatedObjectsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif

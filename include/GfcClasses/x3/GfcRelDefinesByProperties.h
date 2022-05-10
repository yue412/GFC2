#ifndef GFCRELDEFINESBYPROPERTIES_H
#define GFCRELDEFINESBYPROPERTIES_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRelDefines.h"
#include "GfcClasses/x3/GfcPropertySet.h"
#include "GfcClasses/x3/GfcObject.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRelDefinesByProperties: public GfcRelDefines
{
GFCENGINE_DEC_OBJECT(GfcRelDefinesByProperties, gfc::engine::CEntity)
public:
    GfcRelDefinesByProperties();
    GfcRelDefinesByProperties(bool bSetSchema);
    void setRelatingPropertySet(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingPropertySet() const;
    bool hasRelatingPropertySet() const;
    std::shared_ptr<GfcPropertySet> getRelatingPropertySetPtr();
    int getRelatedObjectsCount() const;
    void clearRelatedObjects();
    void addRelatedObjects(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatedObjects(int nIndex) const;
    std::shared_ptr<GfcObject> getRelatedObjectsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif

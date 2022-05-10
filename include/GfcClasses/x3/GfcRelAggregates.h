#ifndef GFCRELAGGREGATES_H
#define GFCRELAGGREGATES_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRelDecomposes.h"
#include "GfcClasses/x3/GfcObject.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRelAggregates: public GfcRelDecomposes
{
GFCENGINE_DEC_OBJECT(GfcRelAggregates, gfc::engine::CEntity)
public:
    GfcRelAggregates();
    GfcRelAggregates(bool bSetSchema);
    void setRelatingObject(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingObject() const;
    bool hasRelatingObject() const;
    std::shared_ptr<GfcObject> getRelatingObjectPtr();
    int getRelatedObjectsCount() const;
    void clearRelatedObjects();
    void addRelatedObjects(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatedObjects(int nIndex) const;
    std::shared_ptr<GfcObject> getRelatedObjectsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif

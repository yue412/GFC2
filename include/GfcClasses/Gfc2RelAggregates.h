#ifndef GFC2RELAGGREGATES_H
#define GFC2RELAGGREGATES_H

#include "GfcClasses.h"
#include "Gfc2RelDecomposes.h"
#include "Gfc2Object.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RelAggregates: public Gfc2RelDecomposes
{
GFCENGINE_DEC_OBJECT(Gfc2RelAggregates, gfc::engine::CEntity)
public:
    Gfc2RelAggregates();
    Gfc2RelAggregates(bool bSetSchema);
    void setRelatingObject(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingObject() const;
    bool hasRelatingObject() const;
    gfc::engine::CEntityWrapPtr<Gfc2Object> getRelatingObjectPtr();
    int getRelatedObjectsCount() const;
    void clearRelatedObjects();
    void addRelatedObjects(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatedObjects(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Object> getRelatedObjectsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif

#ifndef GFC2RELAGGREGATES_H
#define GFC2RELAGGREGATES_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2RelDecomposes.h"
#include "GfcClasses/x3/Gfc2Object.h"
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
    std::shared_ptr<Gfc2Object> getRelatingObjectPtr();
    int getRelatedObjectsCount() const;
    void clearRelatedObjects();
    void addRelatedObjects(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatedObjects(int nIndex) const;
    std::shared_ptr<Gfc2Object> getRelatedObjectsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif

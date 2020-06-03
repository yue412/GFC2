#ifndef GFC2RELAGGREGATES_H
#define GFC2RELAGGREGATES_H

#include "GfcClasses.h"
#include "Gfc2RelDecomposes.h"
#include "Gfc2Object.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelAggregates: public Gfc2RelDecomposes
{
GFCENGINE_DEC_OBJECT(Gfc2RelAggregates, gfc2::engine::Entity)
public:
    Gfc2RelAggregates();
    Gfc2RelAggregates(bool bSetSchema);
    void setRelatingObject(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRelatingObject() const;
    bool hasRelatingObject() const;
    std::shared_ptr<Gfc2Object> getRelatingObjectPtr();
    int getRelatedObjectsCount() const;
    void clearRelatedObjects();
    void addRelatedObjects(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRelatedObjects(int nIndex) const;
    std::shared_ptr<Gfc2Object> getRelatedObjectsPtr(int nIndex);

};
#endif

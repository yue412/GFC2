#ifndef GFCBODY_H
#define GFCBODY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcGeometry.h"
#include "GfcClasses/x3/GfcPropertySet.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcBody: public GfcGeometry
{
GFCENGINE_DEC_OBJECT(GfcBody, gfc::engine::CEntity)
public:
    GfcBody();
    GfcBody(bool bSetSchema);
    void setCustomPropSet(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCustomPropSet() const;
    bool hasCustomPropSet() const;
    std::shared_ptr<GfcPropertySet> getCustomPropSetPtr();

};

GFCCLASSES_NAMESPACE_END

#endif

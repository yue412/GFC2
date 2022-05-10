#ifndef GFCENTITYPROPERTY_H
#define GFCENTITYPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSingleProperty.h"
#include "GfcClasses/x3/GfcRoot.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcEntityProperty: public GfcSingleProperty
{
GFCENGINE_DEC_OBJECT(GfcEntityProperty, gfc::engine::CEntity)
public:
    GfcEntityProperty();
    GfcEntityProperty(bool bSetSchema);
    void setVal(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getVal() const;
    bool hasVal() const;
    std::shared_ptr<GfcRoot> getValPtr();

};

GFCCLASSES_NAMESPACE_END

#endif

#ifndef GFCSECTIONPROPERTY_H
#define GFCSECTIONPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSingleProperty.h"
#include "GfcClasses/x3/GfcSection.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSectionProperty: public GfcSingleProperty
{
GFCENGINE_DEC_OBJECT(GfcSectionProperty, gfc::engine::CEntity)
public:
    GfcSectionProperty();
    GfcSectionProperty(bool bSetSchema);
    void setSection(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSection() const;
    bool hasSection() const;
    std::shared_ptr<GfcSection> getSectionPtr();

};

GFCCLASSES_NAMESPACE_END

#endif

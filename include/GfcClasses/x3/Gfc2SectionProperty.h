#ifndef GFC2SECTIONPROPERTY_H
#define GFC2SECTIONPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2SingleProperty.h"
#include "GfcClasses/x3/Gfc2Section.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2SectionProperty: public Gfc2SingleProperty
{
GFCENGINE_DEC_OBJECT(Gfc2SectionProperty, gfc::engine::CEntity)
public:
    Gfc2SectionProperty();
    Gfc2SectionProperty(bool bSetSchema);
    void setSection(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSection() const;
    bool hasSection() const;
    gfc::engine::CEntityWrapPtr<Gfc2Section> getSectionPtr();

};

GFCCLASSES_NAMESPACE_END

#endif

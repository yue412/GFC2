#ifndef GFC2SECTIONPROPERTY_H
#define GFC2SECTIONPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2SingleProperty.h"
#include "Gfc2Section.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SectionProperty: public Gfc2SingleProperty
{
GFCENGINE_DEC_OBJECT(Gfc2SectionProperty, gfc::engine::Entity)
public:
    Gfc2SectionProperty();
    Gfc2SectionProperty(bool bSetSchema);
    void setSection(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSection() const;
    bool hasSection() const;
    std::shared_ptr<Gfc2Section> getSectionPtr();

};
#endif

#ifndef NGFC2SECTIONPROPERTY_H
#define NGFC2SECTIONPROPERTY_H

#include "NGfc2SingleProperty.h"
#include "Gfc2SectionProperty.h"
#include "NGfc2Section.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2SectionProperty: public NGfc2SingleProperty
{
public:
    NGfc2SectionProperty();
    NGfc2SectionProperty(void* pEntity, bool bOwner);
    void setSection(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getSection();
    bool hasSection();
    NGfc2Section^ getSectionPtr();

};
#endif

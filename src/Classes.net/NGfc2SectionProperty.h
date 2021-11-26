#ifndef NGFC2SECTIONPROPERTY_H
#define NGFC2SECTIONPROPERTY_H

#include "NGfc2SingleProperty.h"
#include "GfcClasses\x3\Gfc2SectionProperty.h"
#include "NGfc2Section.h"

public ref class NGfc2SectionProperty: public NGfc2SingleProperty
{
public:
    NGfc2SectionProperty();
    NGfc2SectionProperty(void* pEntity, bool bOwner);
    void setSection(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSection();
    bool hasSection();

};
#endif

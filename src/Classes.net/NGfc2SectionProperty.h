#ifndef NGFC2SECTIONPROPERTY_H
#define NGFC2SECTIONPROPERTY_H

#include "NGfc2SingleProperty.h"
#include "Gfc2SectionProperty.h"
#include "NGfc2Section.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2SectionProperty: public NGfc2SingleProperty
{
public:
    NGfc2SectionProperty();
    NGfc2SectionProperty(void* pEntity, bool bOwner);
    void setSection(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getSection();
    bool hasSection();
    NGfc2Section^ getSectionPtr();

};
#endif

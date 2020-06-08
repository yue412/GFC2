#ifndef NGFC2SECTIONLISTPROPERTY_H
#define NGFC2SECTIONLISTPROPERTY_H

#include "NGfc2ListProperty.h"
#include "Gfc2SectionListProperty.h"
#include "NGfc2Section.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2SectionListProperty: public NGfc2ListProperty
{
public:
    NGfc2SectionListProperty();
    NGfc2SectionListProperty(void* pEntity, bool bOwner);
    int getValueCount();
    void clearValue();
    void addValue(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getValue(int nIndex);
    NGfc2Section^ getValuePtr(int nIndex);

};
#endif

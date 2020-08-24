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
    int getValuesCount();
    void clearValues();
    void addValues(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getValues(int nIndex);
    NGfc2Section^ getValuesPtr(int nIndex);

};
#endif

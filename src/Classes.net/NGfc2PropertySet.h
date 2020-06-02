#ifndef NGFC2PROPERTYSET_H
#define NGFC2PROPERTYSET_H

#include "Gfc2PropertySet.h"
#include "NGfc2Property.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2PropertySet: public glodon::objectbufnet::Entity
{
public:
    NGfc2PropertySet();
    NGfc2PropertySet(void* pEntity, bool bOwner);
    int getHasPropertiesCount();
    void clearHasProperties();
    void addHasProperties(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getHasProperties(int nIndex);
    NGfc2Property^ getHasPropertiesPtr(int nIndex);

};
#endif

#ifndef NGFC2PROPERTYSET_H
#define NGFC2PROPERTYSET_H

#include "NGfc2Root.h"
#include "Gfc2PropertySet.h"
#include "NGfc2Property.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2PropertySet: public NGfc2Root
{
public:
    NGfc2PropertySet();
    NGfc2PropertySet(void* pEntity, bool bOwner);
    void setIdentifier(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getIdentifier();
    bool hasIdentifier();
    NGfc2Label^ getIdentifierPtr();
    int getHasPropertiesCount();
    void clearHasProperties();
    void addHasProperties(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getHasProperties(int nIndex);
    NGfc2Property^ getHasPropertiesPtr(int nIndex);

};
#endif

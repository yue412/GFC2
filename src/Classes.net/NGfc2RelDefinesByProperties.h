#ifndef NGFC2RELDEFINESBYPROPERTIES_H
#define NGFC2RELDEFINESBYPROPERTIES_H

#include "NGfc2RelDefines.h"
#include "Gfc2RelDefinesByProperties.h"
#include "NGfc2PropertySet.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2RelDefinesByProperties: public NGfc2RelDefines
{
public:
    NGfc2RelDefinesByProperties();
    NGfc2RelDefinesByProperties(void* pEntity, bool bOwner);
    void setRelatingPropertySet(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRelatingPropertySet();
    bool hasRelatingPropertySet();
    NGfc2PropertySet^ getRelatingPropertySetPtr();

};
#endif

#ifndef NGFC2PROPERTY_H
#define NGFC2PROPERTY_H

#include "Gfc2Property.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Property: public glodon::objectbufnet::Entity
{
public:
    NGfc2Property();
    NGfc2Property(void* pEntity, bool bOwner);
    void setName(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getName();
    bool hasName();
    NGfc2Label^ getNamePtr();

};
#endif

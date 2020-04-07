#ifndef NGFC2RELATIONSHIP_H
#define NGFC2RELATIONSHIP_H

#include "Gfc2RelationShip.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2RelationShip: public glodon::objectbufnet::Entity
{
public:
    NGfc2RelationShip();
    NGfc2RelationShip(void* pEntity, bool bOwner);
    void setName(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getName();
    bool hasName();
    NGfc2Label^ getNamePtr();

};
#endif

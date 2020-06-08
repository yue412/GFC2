#ifndef NGFC2RELATIONSHIP_H
#define NGFC2RELATIONSHIP_H

#include "Gfc2RelationShip.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2RelationShip: public glodon::objectbufnet::Entity
{
public:
    NGfc2RelationShip();
    NGfc2RelationShip(void* pEntity, bool bOwner);
    void setName(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getName();
    bool hasName();
    NGfc2Label^ getNamePtr();

};
#endif

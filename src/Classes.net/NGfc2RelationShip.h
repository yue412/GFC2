#ifndef NGFC2RELATIONSHIP_H
#define NGFC2RELATIONSHIP_H

#include "NGfc2Root.h"
#include "Gfc2RelationShip.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2RelationShip: public NGfc2Root
{
public:
    NGfc2RelationShip();
    NGfc2RelationShip(void* pEntity, bool bOwner);

};
#endif

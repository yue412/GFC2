#ifndef NGFC2RELDEFINES_H
#define NGFC2RELDEFINES_H

#include "NGfc2RelationShip.h"
#include "Gfc2RelDefines.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2RelDefines: public NGfc2RelationShip
{
public:
    NGfc2RelDefines();
    NGfc2RelDefines(void* pEntity, bool bOwner);

};
#endif

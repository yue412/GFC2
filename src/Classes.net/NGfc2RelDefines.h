#ifndef NGFC2RELDEFINES_H
#define NGFC2RELDEFINES_H

#include "NGfc2RelationShip.h"
#include "Gfc2RelDefines.h"
#include "NGfc2Object.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2RelDefines: public NGfc2RelationShip
{
public:
    NGfc2RelDefines();
    NGfc2RelDefines(void* pEntity, bool bOwner);
    int getRelatedObjectsCount();
    void clearRelatedObjects();
    void addRelatedObjects(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRelatedObjects(int nIndex);
    NGfc2Object^ getRelatedObjectsPtr(int nIndex);

};
#endif

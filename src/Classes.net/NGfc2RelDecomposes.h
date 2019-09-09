#ifndef NGFC2RELDECOMPOSES_H
#define NGFC2RELDECOMPOSES_H

#include "NGfc2RelationShip.h"
#include "Gfc2RelDecomposes.h"
#include "NGfc2Object.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2RelDecomposes: public NGfc2RelationShip
{
public:
    NGfc2RelDecomposes();
    NGfc2RelDecomposes(void* pEntity, bool bOwner);
    void setRelatingObject(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRelatingObject();
    bool hasRelatingObject();
    NGfc2Object^ getRelatingObjectPtr();
    int getRelatedObjectsCount();
    void clearRelatedObjects();
    void addRelatedObjects(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRelatedObjects(int nIndex);
    NGfc2Object^ getRelatedObjectsPtr(int nIndex);

};
#endif

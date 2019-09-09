#ifndef NGFC2REPRESENTATION_H
#define NGFC2REPRESENTATION_H

#include "Gfc2Representation.h"
#include "NGfc2String.h"
#include "NGfc2RepresentationItem.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Representation: public glodon::objectbufnet::Entity
{
public:
    NGfc2Representation();
    NGfc2Representation(void* pEntity, bool bOwner);
    void setIdentifier(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getIdentifier();
    bool hasIdentifier();
    NGfc2String^ getIdentifierPtr();
    int getitemsCount();
    void clearitems();
    void additems(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getitems(int nIndex);
    NGfc2RepresentationItem^ getitemsPtr(int nIndex);

};
#endif

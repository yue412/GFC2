#ifndef NGFC2REPRESENTATION_H
#define NGFC2REPRESENTATION_H

#include "Gfc2Representation.h"
#include "NGfc2String.h"
#include "NGfc2RepresentationItem.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Representation: public glodon::objectbufnet::Entity
{
public:
    NGfc2Representation();
    NGfc2Representation(void* pEntity, bool bOwner);
    void setIdentifier(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getIdentifier();
    bool hasIdentifier();
    NGfc2String^ getIdentifierPtr();
    int getitemsCount();
    void clearitems();
    void additems(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getitems(int nIndex);
    NGfc2RepresentationItem^ getitemsPtr(int nIndex);

};
#endif

#ifndef GFC2RELATIONSHIP_H
#define GFC2RELATIONSHIP_H

#include "GfcClasses.h"
#include "Gfc2Root.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RelationShip: public Gfc2Root
{
OBJECTBUF_DEC_OBJECT(Gfc2RelationShip,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

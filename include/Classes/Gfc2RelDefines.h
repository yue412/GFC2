#ifndef GFC2RELDEFINES_H
#define GFC2RELDEFINES_H

#include "GfcClasses.h"
#include "Gfc2RelationShip.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RelDefines: public Gfc2RelationShip
{
OBJECTBUF_DEC_OBJECT(Gfc2RelDefines,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

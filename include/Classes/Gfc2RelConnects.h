#ifndef GFC2RELCONNECTS_H
#define GFC2RELCONNECTS_H

#include "GfcClasses.h"
#include "Gfc2RelationShip.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RelConnects: public Gfc2RelationShip
{
OBJECTBUF_DEC_OBJECT(Gfc2RelConnects,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

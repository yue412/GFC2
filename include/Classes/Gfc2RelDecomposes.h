#ifndef GFC2RELDECOMPOSES_H
#define GFC2RELDECOMPOSES_H

#include "GfcClasses.h"
#include "Gfc2RelationShip.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RelDecomposes: public Gfc2RelationShip
{
OBJECTBUF_DEC_OBJECT(Gfc2RelDecomposes,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

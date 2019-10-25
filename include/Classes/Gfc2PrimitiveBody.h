#ifndef GFC2PRIMITIVEBODY_H
#define GFC2PRIMITIVEBODY_H

#include "GfcClasses.h"
#include "Gfc2Body.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2PrimitiveBody: public Gfc2Body
{
OBJECTBUF_DEC_OBJECT(Gfc2PrimitiveBody,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

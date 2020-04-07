#ifndef GFC2SIMPLEPROPERTY_H
#define GFC2SIMPLEPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2Property.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2SimpleProperty: public Gfc2Property
{
OBJECTBUF_DEC_OBJECT(Gfc2SimpleProperty,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

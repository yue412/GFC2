#ifndef GFC2LISTPROPERTY_H
#define GFC2LISTPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2SimpleProperty.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ListProperty: public Gfc2SimpleProperty
{
OBJECTBUF_DEC_OBJECT(Gfc2ListProperty,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

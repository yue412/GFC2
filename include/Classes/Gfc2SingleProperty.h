#ifndef GFC2SINGLEPROPERTY_H
#define GFC2SINGLEPROPERTY_H

#include "GfcClasses.h"
#include "Gfc2SimpleProperty.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2SingleProperty: public Gfc2SimpleProperty
{
OBJECTBUF_DEC_OBJECT(Gfc2SingleProperty,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

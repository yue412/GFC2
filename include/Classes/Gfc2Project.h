#ifndef GFC2PROJECT_H
#define GFC2PROJECT_H

#include "GfcClasses.h"
#include "Gfc2Object.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Project: public Gfc2Object
{
OBJECTBUF_DEC_OBJECT(Gfc2Project,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

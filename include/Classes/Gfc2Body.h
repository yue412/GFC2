#ifndef GFC2BODY_H
#define GFC2BODY_H

#include "GfcClasses.h"
#include "Gfc2Geometry.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Body: public Gfc2Geometry
{
OBJECTBUF_DEC_OBJECT(Gfc2Body,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

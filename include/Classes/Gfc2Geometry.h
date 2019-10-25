#ifndef GFC2GEOMETRY_H
#define GFC2GEOMETRY_H

#include "GfcClasses.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Geometry: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2Geometry,glodon::objectbuf::Entity)
public:
    Gfc2Geometry();
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

protected:
    unsigned _has_bits_[1];
};
#endif

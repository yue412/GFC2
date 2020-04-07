#ifndef GFC2CONNECTIONGEOMETRY_H
#define GFC2CONNECTIONGEOMETRY_H

#include "GfcClasses.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ConnectionGeometry: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2ConnectionGeometry,glodon::objectbuf::Entity)
public:
    Gfc2ConnectionGeometry();
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

protected:
    unsigned _has_bits_[1];
};
#endif

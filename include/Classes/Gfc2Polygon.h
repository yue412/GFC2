#ifndef GFC2POLYGON_H
#define GFC2POLYGON_H

#include "GfcClasses.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2Polygon: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2Polygon,glodon::objectbuf::Entity)
public:
    Gfc2Polygon();
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

protected:
    unsigned _has_bits_[1];
};
#endif

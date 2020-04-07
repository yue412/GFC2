#ifndef GFC2REPRESENTATIONITEM_H
#define GFC2REPRESENTATIONITEM_H

#include "GfcClasses.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RepresentationItem: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2RepresentationItem,glodon::objectbuf::Entity)
public:
    Gfc2RepresentationItem();
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

protected:
    unsigned _has_bits_[1];
};
#endif

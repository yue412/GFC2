#ifndef GFC2SECTION_H
#define GFC2SECTION_H

#include "GfcClasses.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Section: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2Section,glodon::objectbuf::Entity)
public:
    Gfc2Section();
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

protected:
    unsigned _has_bits_[1];
};
#endif

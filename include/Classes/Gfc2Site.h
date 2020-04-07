#ifndef GFC2SITE_H
#define GFC2SITE_H

#include "GfcClasses.h"
#include "Gfc2SpatialStructureElement.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Site: public Gfc2SpatialStructureElement
{
OBJECTBUF_DEC_OBJECT(Gfc2Site,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

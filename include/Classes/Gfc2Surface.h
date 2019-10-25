#ifndef GFC2SURFACE_H
#define GFC2SURFACE_H

#include "GfcClasses.h"
#include "Gfc2Geometry.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Surface: public Gfc2Geometry
{
OBJECTBUF_DEC_OBJECT(Gfc2Surface,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

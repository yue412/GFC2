#ifndef GFC2AXISGRID_H
#define GFC2AXISGRID_H

#include "GfcClasses.h"
#include "Gfc2Entity.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2AxisGrid: public Gfc2Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2AxisGrid,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

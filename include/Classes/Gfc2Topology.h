#ifndef GFC2TOPOLOGY_H
#define GFC2TOPOLOGY_H

#include "GfcClasses.h"
#include "Gfc2Geometry.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Topology: public Gfc2Geometry
{
OBJECTBUF_DEC_OBJECT(Gfc2Topology,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

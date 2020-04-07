#ifndef GFC2POLYGON_H
#define GFC2POLYGON_H

#include "GfcClasses.h"
#include "Gfc2Topology.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Polygon: public Gfc2Topology
{
OBJECTBUF_DEC_OBJECT(Gfc2Polygon,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

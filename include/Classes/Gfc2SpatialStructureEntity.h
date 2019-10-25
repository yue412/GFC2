#ifndef GFC2SPATIALSTRUCTUREENTITY_H
#define GFC2SPATIALSTRUCTUREENTITY_H

#include "GfcClasses.h"
#include "Gfc2Object.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2SpatialStructureEntity: public Gfc2Object
{
OBJECTBUF_DEC_OBJECT(Gfc2SpatialStructureEntity,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

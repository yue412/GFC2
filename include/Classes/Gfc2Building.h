#ifndef GFC2BUILDING_H
#define GFC2BUILDING_H

#include "GfcClasses.h"
#include "Gfc2SpatialStructureElement.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2Building: public Gfc2SpatialStructureElement
{
OBJECTBUF_DEC_OBJECT(Gfc2Building,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

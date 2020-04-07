#ifndef GFC2PRIMITIVESHAPE_H
#define GFC2PRIMITIVESHAPE_H

#include "GfcClasses.h"
#include "Gfc2SolidShape.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2PrimitiveShape: public Gfc2SolidShape
{
OBJECTBUF_DEC_OBJECT(Gfc2PrimitiveShape,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

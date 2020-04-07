#ifndef GFC2SOLIDSHAPE_H
#define GFC2SOLIDSHAPE_H

#include "GfcClasses.h"
#include "Gfc2ParametricShape.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2SolidShape: public Gfc2ParametricShape
{
OBJECTBUF_DEC_OBJECT(Gfc2SolidShape,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

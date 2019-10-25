#ifndef GFC2PARAMETRICSHAPE_H
#define GFC2PARAMETRICSHAPE_H

#include "GfcClasses.h"
#include "Gfc2Shape.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ParametricShape: public Gfc2Shape
{
OBJECTBUF_DEC_OBJECT(Gfc2ParametricShape,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

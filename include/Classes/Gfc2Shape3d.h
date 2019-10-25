#ifndef GFC2SHAPE3D_H
#define GFC2SHAPE3D_H

#include "GfcClasses.h"
#include "Gfc2ParametricShape.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Shape3d: public Gfc2ParametricShape
{
OBJECTBUF_DEC_OBJECT(Gfc2Shape3d,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

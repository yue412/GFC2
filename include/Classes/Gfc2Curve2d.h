#ifndef GFC2CURVE2D_H
#define GFC2CURVE2D_H

#include "GfcClasses.h"
#include "Gfc2Geometry.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Curve2d: public Gfc2Geometry
{
OBJECTBUF_DEC_OBJECT(Gfc2Curve2d,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

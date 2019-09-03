#ifndef GFC2CURVE3D_H
#define GFC2CURVE3D_H

#include "GfcClasses.h"
#include "Gfc2Geometry.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2Curve3d: public Gfc2Geometry
{
OBJECTBUF_DEC_OBJECT(Gfc2Curve3d,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

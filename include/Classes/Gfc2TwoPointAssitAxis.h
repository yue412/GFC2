#ifndef GFC2TWOPOINTASSITAXIS_H
#define GFC2TWOPOINTASSITAXIS_H

#include "GfcClasses.h"
#include "Gfc2AssitAxis.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2TwoPointAssitAxis: public Gfc2AssitAxis
{
OBJECTBUF_DEC_OBJECT(Gfc2TwoPointAssitAxis,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

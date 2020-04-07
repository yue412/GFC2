#ifndef GFC2LIGHTSOURCEAMBIENT_H
#define GFC2LIGHTSOURCEAMBIENT_H

#include "GfcClasses.h"
#include "Gfc2LightSource.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2LightSourceAmbient: public Gfc2LightSource
{
OBJECTBUF_DEC_OBJECT(Gfc2LightSourceAmbient,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

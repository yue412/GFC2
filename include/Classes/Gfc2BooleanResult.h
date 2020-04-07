#ifndef GFC2BOOLEANRESULT_H
#define GFC2BOOLEANRESULT_H

#include "GfcClasses.h"
#include "Gfc2SolidShape.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2BooleanResult: public Gfc2SolidShape
{
OBJECTBUF_DEC_OBJECT(Gfc2BooleanResult,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

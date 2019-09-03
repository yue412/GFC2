#ifndef GFC2RELNESTS_H
#define GFC2RELNESTS_H

#include "GfcClasses.h"
#include "Gfc2RelDecomposes.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2RelNests: public Gfc2RelDecomposes
{
OBJECTBUF_DEC_OBJECT(Gfc2RelNests,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif

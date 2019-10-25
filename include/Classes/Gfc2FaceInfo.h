#ifndef GFC2FACEINFO_H
#define GFC2FACEINFO_H

#include "GfcClasses.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2FaceInfo: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2FaceInfo,glodon::objectbuf::Entity)
public:
    Gfc2FaceInfo();
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

protected:
    unsigned _has_bits_[1];
};
#endif

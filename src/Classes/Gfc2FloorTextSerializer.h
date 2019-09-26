#ifndef GFC2FLOORTEXTSERIALIZER_H
#define GFC2FLOORTEXTSERIALIZER_H

#include "Gfc2SpatialStructureEntityTextSerializer.h"

class Gfc2FloorTextSerializer: public Gfc2SpatialStructureEntityTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2FloorTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

#ifndef GFC2COORDINATES2DTEXTSERIALIZER_H
#define GFC2COORDINATES2DTEXTSERIALIZER_H

#include "Gfc2GeometryTextSerializer.h"

class Gfc2Coordinates2dTextSerializer: public Gfc2GeometryTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2Coordinates2dTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

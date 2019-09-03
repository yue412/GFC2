#ifndef GFC2FACESHAPE2DTEXTSERIALIZER_H
#define GFC2FACESHAPE2DTEXTSERIALIZER_H

#include "Gfc2Shape2dTextSerializer.h"

class Gfc2FaceShape2dTextSerializer: public Gfc2Shape2dTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2FaceShape2dTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

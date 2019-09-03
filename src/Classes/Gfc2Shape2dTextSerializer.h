#ifndef GFC2SHAPE2DTEXTSERIALIZER_H
#define GFC2SHAPE2DTEXTSERIALIZER_H

#include "Gfc2ParametricShapeTextSerializer.h"

class Gfc2Shape2dTextSerializer: public Gfc2ParametricShapeTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2Shape2dTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

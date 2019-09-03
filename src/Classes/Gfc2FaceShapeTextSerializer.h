#ifndef GFC2FACESHAPETEXTSERIALIZER_H
#define GFC2FACESHAPETEXTSERIALIZER_H

#include "Gfc2SolidShapeTextSerializer.h"

class Gfc2FaceShapeTextSerializer: public Gfc2SolidShapeTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2FaceShapeTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

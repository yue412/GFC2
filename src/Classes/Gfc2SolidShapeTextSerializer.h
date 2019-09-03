#ifndef GFC2SOLIDSHAPETEXTSERIALIZER_H
#define GFC2SOLIDSHAPETEXTSERIALIZER_H

#include "Gfc2Shape3dTextSerializer.h"

class Gfc2SolidShapeTextSerializer: public Gfc2Shape3dTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2SolidShapeTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

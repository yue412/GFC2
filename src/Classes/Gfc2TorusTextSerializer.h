#ifndef GFC2TORUSTEXTSERIALIZER_H
#define GFC2TORUSTEXTSERIALIZER_H

#include "Gfc2SurfaceTextSerializer.h"

class Gfc2TorusTextSerializer: public Gfc2SurfaceTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2TorusTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

#ifndef GFC2SPHERETEXTSERIALIZER_H
#define GFC2SPHERETEXTSERIALIZER_H

#include "Gfc2SurfaceTextSerializer.h"

class Gfc2SphereTextSerializer: public Gfc2SurfaceTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2SphereTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

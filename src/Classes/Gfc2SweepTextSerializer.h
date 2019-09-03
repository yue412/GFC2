#ifndef GFC2SWEEPTEXTSERIALIZER_H
#define GFC2SWEEPTEXTSERIALIZER_H

#include "Gfc2SurfaceTextSerializer.h"

class Gfc2SweepTextSerializer: public Gfc2SurfaceTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2SweepTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

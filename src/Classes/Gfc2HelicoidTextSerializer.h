#ifndef GFC2HELICOIDTEXTSERIALIZER_H
#define GFC2HELICOIDTEXTSERIALIZER_H

#include "Gfc2SurfaceTextSerializer.h"

class Gfc2HelicoidTextSerializer: public Gfc2SurfaceTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2HelicoidTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

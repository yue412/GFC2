#ifndef GFC2EXTRUDEDBODYTEXTSERIALIZER_H
#define GFC2EXTRUDEDBODYTEXTSERIALIZER_H

#include "Gfc2PrimitiveBodyTextSerializer.h"

class Gfc2ExtrudedBodyTextSerializer: public Gfc2PrimitiveBodyTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2ExtrudedBodyTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

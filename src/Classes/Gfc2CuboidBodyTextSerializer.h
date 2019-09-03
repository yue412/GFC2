#ifndef GFC2CUBOIDBODYTEXTSERIALIZER_H
#define GFC2CUBOIDBODYTEXTSERIALIZER_H

#include "Gfc2BodyTextSerializer.h"

class Gfc2CuboidBodyTextSerializer: public Gfc2BodyTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2CuboidBodyTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

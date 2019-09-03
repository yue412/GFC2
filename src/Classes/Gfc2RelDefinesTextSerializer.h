#ifndef GFC2RELDEFINESTEXTSERIALIZER_H
#define GFC2RELDEFINESTEXTSERIALIZER_H

#include "Gfc2RelationShipTextSerializer.h"

class Gfc2RelDefinesTextSerializer: public Gfc2RelationShipTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2RelDefinesTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

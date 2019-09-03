#ifndef GFC2RELDEFINESBYPROPERTIESTEXTSERIALIZER_H
#define GFC2RELDEFINESBYPROPERTIESTEXTSERIALIZER_H

#include "Gfc2RelDefinesTextSerializer.h"

class Gfc2RelDefinesByPropertiesTextSerializer: public Gfc2RelDefinesTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2RelDefinesByPropertiesTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

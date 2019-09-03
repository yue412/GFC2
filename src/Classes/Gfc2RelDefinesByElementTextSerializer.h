#ifndef GFC2RELDEFINESBYELEMENTTEXTSERIALIZER_H
#define GFC2RELDEFINESBYELEMENTTEXTSERIALIZER_H

#include "Gfc2RelDefinesTextSerializer.h"

class Gfc2RelDefinesByElementTextSerializer: public Gfc2RelDefinesTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2RelDefinesByElementTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

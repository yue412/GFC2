#ifndef GFC2ABNORMITYLINEARCHINFOTEXTSERIALIZER_H
#define GFC2ABNORMITYLINEARCHINFOTEXTSERIALIZER_H

#include "Gfc2BaseLineArcInfoTextSerializer.h"

class Gfc2AbnormityLineArchInfoTextSerializer: public Gfc2BaseLineArcInfoTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2AbnormityLineArchInfoTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

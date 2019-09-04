#ifndef GFC2EDGEDATATEXTSERIALIZER_H
#define GFC2EDGEDATATEXTSERIALIZER_H

#include "glodon/objectbuf/EntityTextSerializer.h"

class Gfc2EdgeDataTextSerializer: public glodon::objectbuf::EntityTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2EdgeDataTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif
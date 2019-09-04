#ifndef GFC2STATESETTEXTSERIALIZER_H
#define GFC2STATESETTEXTSERIALIZER_H

#include "glodon/objectbuf/EntityTextSerializer.h"

class Gfc2StateSetTextSerializer: public glodon::objectbuf::EntityTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2StateSetTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif
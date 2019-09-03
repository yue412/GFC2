#ifndef GFC2ENTITYTEXTSERIALIZER_H
#define GFC2ENTITYTEXTSERIALIZER_H

#include "Gfc2ObjectTextSerializer.h"

class Gfc2EntityTextSerializer: public Gfc2ObjectTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2EntityTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

#ifndef GFC2INTEGERPROPERTYTEXTSERIALIZER_H
#define GFC2INTEGERPROPERTYTEXTSERIALIZER_H

#include "Gfc2PropertyTextSerializer.h"

class Gfc2IntegerPropertyTextSerializer: public Gfc2PropertyTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2IntegerPropertyTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

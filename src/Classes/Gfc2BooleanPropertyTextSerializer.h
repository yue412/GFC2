#ifndef GFC2BOOLEANPROPERTYTEXTSERIALIZER_H
#define GFC2BOOLEANPROPERTYTEXTSERIALIZER_H

#include "Gfc2PropertyTextSerializer.h"

class Gfc2BooleanPropertyTextSerializer: public Gfc2PropertyTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2BooleanPropertyTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

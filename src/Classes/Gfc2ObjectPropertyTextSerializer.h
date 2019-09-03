#ifndef GFC2OBJECTPROPERTYTEXTSERIALIZER_H
#define GFC2OBJECTPROPERTYTEXTSERIALIZER_H

#include "Gfc2PropertyTextSerializer.h"

class Gfc2ObjectPropertyTextSerializer: public Gfc2PropertyTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2ObjectPropertyTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

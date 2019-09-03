#ifndef GFC2BREPBODYTEXTSERIALIZER_H
#define GFC2BREPBODYTEXTSERIALIZER_H

#include "Gfc2BodyTextSerializer.h"

class Gfc2BrepBodyTextSerializer: public Gfc2BodyTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2BrepBodyTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

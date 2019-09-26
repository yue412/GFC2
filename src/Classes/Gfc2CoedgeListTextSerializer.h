#ifndef GFC2COEDGELISTTEXTSERIALIZER_H
#define GFC2COEDGELISTTEXTSERIALIZER_H

#include "Gfc2GeometryTextSerializer.h"

class Gfc2CoedgeListTextSerializer: public Gfc2GeometryTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2CoedgeListTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

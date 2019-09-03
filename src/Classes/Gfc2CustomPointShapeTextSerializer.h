#ifndef GFC2CUSTOMPOINTSHAPETEXTSERIALIZER_H
#define GFC2CUSTOMPOINTSHAPETEXTSERIALIZER_H

#include "Gfc2SolidShapeTextSerializer.h"

class Gfc2CustomPointShapeTextSerializer: public Gfc2SolidShapeTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2CustomPointShapeTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

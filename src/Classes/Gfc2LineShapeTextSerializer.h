#ifndef GFC2LINESHAPETEXTSERIALIZER_H
#define GFC2LINESHAPETEXTSERIALIZER_H

#include "Gfc2CustomLineShapeTextSerializer.h"

class Gfc2LineShapeTextSerializer: public Gfc2CustomLineShapeTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2LineShapeTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

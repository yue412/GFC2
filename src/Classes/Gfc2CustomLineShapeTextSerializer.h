#ifndef GFC2CUSTOMLINESHAPETEXTSERIALIZER_H
#define GFC2CUSTOMLINESHAPETEXTSERIALIZER_H

#include "Gfc2SolidShapeTextSerializer.h"

class Gfc2CustomLineShapeTextSerializer: public Gfc2SolidShapeTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2CustomLineShapeTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

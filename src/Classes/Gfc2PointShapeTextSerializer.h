#ifndef GFC2POINTSHAPETEXTSERIALIZER_H
#define GFC2POINTSHAPETEXTSERIALIZER_H

#include "Gfc2SectionPointShapeTextSerializer.h"

class Gfc2PointShapeTextSerializer: public Gfc2SectionPointShapeTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2PointShapeTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

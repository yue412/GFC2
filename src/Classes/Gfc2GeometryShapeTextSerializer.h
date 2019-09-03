#ifndef GFC2GEOMETRYSHAPETEXTSERIALIZER_H
#define GFC2GEOMETRYSHAPETEXTSERIALIZER_H

#include "Gfc2ShapeTextSerializer.h"

class Gfc2GeometryShapeTextSerializer: public Gfc2ShapeTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2GeometryShapeTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

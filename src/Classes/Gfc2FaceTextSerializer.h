#ifndef GFC2FACETEXTSERIALIZER_H
#define GFC2FACETEXTSERIALIZER_H

#include "Gfc2CommonPolygonExTextSerializer.h"

class Gfc2FaceTextSerializer: public Gfc2CommonPolygonExTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2FaceTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

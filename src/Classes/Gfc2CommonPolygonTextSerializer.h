#ifndef GFC2COMMONPOLYGONTEXTSERIALIZER_H
#define GFC2COMMONPOLYGONTEXTSERIALIZER_H

#include "Gfc2PolygonTextSerializer.h"

class Gfc2CommonPolygonTextSerializer: public Gfc2PolygonTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2CommonPolygonTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

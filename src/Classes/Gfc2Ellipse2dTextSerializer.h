#ifndef GFC2ELLIPSE2DTEXTSERIALIZER_H
#define GFC2ELLIPSE2DTEXTSERIALIZER_H

#include "Gfc2Curve2dTextSerializer.h"

class Gfc2Ellipse2dTextSerializer: public Gfc2Curve2dTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2Ellipse2dTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

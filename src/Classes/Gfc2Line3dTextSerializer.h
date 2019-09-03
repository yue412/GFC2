#ifndef GFC2LINE3DTEXTSERIALIZER_H
#define GFC2LINE3DTEXTSERIALIZER_H

#include "Gfc2Curve3dTextSerializer.h"

class Gfc2Line3dTextSerializer: public Gfc2Curve3dTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2Line3dTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

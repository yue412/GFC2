#ifndef GFC2POLARAXISGRIDTEXTSERIALIZER_H
#define GFC2POLARAXISGRIDTEXTSERIALIZER_H

#include "Gfc2AxisGridTextSerializer.h"

class Gfc2PolarAxisGridTextSerializer: public Gfc2AxisGridTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2PolarAxisGridTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

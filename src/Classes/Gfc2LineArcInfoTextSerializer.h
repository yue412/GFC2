#ifndef GFC2LINEARCINFOTEXTSERIALIZER_H
#define GFC2LINEARCINFOTEXTSERIALIZER_H

#include "Gfc2BaseLineArcInfoTextSerializer.h"

class Gfc2LineArcInfoTextSerializer: public Gfc2BaseLineArcInfoTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2LineArcInfoTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

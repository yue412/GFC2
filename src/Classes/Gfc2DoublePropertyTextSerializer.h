#ifndef GFC2DOUBLEPROPERTYTEXTSERIALIZER_H
#define GFC2DOUBLEPROPERTYTEXTSERIALIZER_H

#include "Gfc2PropertyTextSerializer.h"

class Gfc2DoublePropertyTextSerializer: public Gfc2PropertyTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2DoublePropertyTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

#ifndef GFC2SIZEMARKTEXTSERIALIZER_H
#define GFC2SIZEMARKTEXTSERIALIZER_H

#include "Gfc2EntityTextSerializer.h"

class Gfc2SizeMarkTextSerializer: public Gfc2EntityTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2SizeMarkTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

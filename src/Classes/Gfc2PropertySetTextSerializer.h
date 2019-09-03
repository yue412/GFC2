#ifndef GFC2PROPERTYSETTEXTSERIALIZER_H
#define GFC2PROPERTYSETTEXTSERIALIZER_H

#include "Gfc2RootTextSerializer.h"

class Gfc2PropertySetTextSerializer: public Gfc2RootTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2PropertySetTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

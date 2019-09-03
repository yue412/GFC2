#ifndef GFC2FACEARCHINFOTEXTSERIALIZER_H
#define GFC2FACEARCHINFOTEXTSERIALIZER_H

#include "Gfc2FaceInfoTextSerializer.h"

class Gfc2FaceArchInfoTextSerializer: public Gfc2FaceInfoTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2FaceArchInfoTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

#ifndef GFC2FACECONEINFOTEXTSERIALIZER_H
#define GFC2FACECONEINFOTEXTSERIALIZER_H

#include "Gfc2FaceInfoTextSerializer.h"

class Gfc2FaceConeInfoTextSerializer: public Gfc2FaceInfoTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2FaceConeInfoTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

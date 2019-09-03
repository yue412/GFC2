#ifndef GFC2FACESPHEREINFOTEXTSERIALIZER_H
#define GFC2FACESPHEREINFOTEXTSERIALIZER_H

#include "Gfc2FaceInfoTextSerializer.h"

class Gfc2FaceSphereInfoTextSerializer: public Gfc2FaceInfoTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2FaceSphereInfoTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

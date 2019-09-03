#ifndef GFC2DOUBLEPROPERTYBINARYSERIALIZER_H
#define GFC2DOUBLEPROPERTYBINARYSERIALIZER_H

#include "Gfc2PropertyBinarySerializer.h"

class Gfc2DoublePropertyBinarySerializer: public Gfc2PropertyBinarySerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2DoublePropertyBinarySerializer,glodon::objectbuf::EntitySerializer)
public:
    int byteSize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual void serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const;
    virtual google::protobuf::uint8* serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const;
    virtual glodon::objectbuf::EnParseFieldState parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

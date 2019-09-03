#ifndef GFC2OBJECTBINARYSERIALIZER_H
#define GFC2OBJECTBINARYSERIALIZER_H

#include "Gfc2RootBinarySerializer.h"

class Gfc2ObjectBinarySerializer: public Gfc2RootBinarySerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2ObjectBinarySerializer,glodon::objectbuf::EntitySerializer)
public:
    int byteSize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual void serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const;
    virtual google::protobuf::uint8* serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const;
    virtual glodon::objectbuf::EnParseFieldState parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

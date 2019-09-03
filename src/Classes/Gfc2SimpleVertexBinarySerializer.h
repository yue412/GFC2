#ifndef GFC2SIMPLEVERTEXBINARYSERIALIZER_H
#define GFC2SIMPLEVERTEXBINARYSERIALIZER_H

#include "glodon/objectbuf/EntityBinarySerializer.h"

class Gfc2SimpleVertexBinarySerializer: public glodon::objectbuf::EntityBinarySerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2SimpleVertexBinarySerializer,glodon::objectbuf::EntitySerializer)
public:
    int byteSize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual void serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const;
    virtual google::protobuf::uint8* serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const;
    virtual glodon::objectbuf::EnParseFieldState parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

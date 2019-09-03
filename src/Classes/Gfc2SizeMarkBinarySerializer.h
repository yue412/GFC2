#ifndef GFC2SIZEMARKBINARYSERIALIZER_H
#define GFC2SIZEMARKBINARYSERIALIZER_H

#include "Gfc2EntityBinarySerializer.h"

class Gfc2SizeMarkBinarySerializer: public Gfc2EntityBinarySerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2SizeMarkBinarySerializer,glodon::objectbuf::EntitySerializer)
public:
    int byteSize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual void serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const;
    virtual google::protobuf::uint8* serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const;
    virtual glodon::objectbuf::EnParseFieldState parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

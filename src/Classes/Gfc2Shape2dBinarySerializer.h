#ifndef GFC2SHAPE2DBINARYSERIALIZER_H
#define GFC2SHAPE2DBINARYSERIALIZER_H

#include "Gfc2ParametricShapeBinarySerializer.h"

class Gfc2Shape2dBinarySerializer: public Gfc2ParametricShapeBinarySerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2Shape2dBinarySerializer,glodon::objectbuf::EntitySerializer)
public:
    int byteSize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual void serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const;
    virtual google::protobuf::uint8* serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const;
    virtual glodon::objectbuf::EnParseFieldState parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

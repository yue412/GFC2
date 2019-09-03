#ifndef GFC2CARTESIANAXISGRIDBINARYSERIALIZER_H
#define GFC2CARTESIANAXISGRIDBINARYSERIALIZER_H

#include "Gfc2AxisGridBinarySerializer.h"

class Gfc2CartesianAxisGridBinarySerializer: public Gfc2AxisGridBinarySerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2CartesianAxisGridBinarySerializer,glodon::objectbuf::EntitySerializer)
public:
    int byteSize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual void serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const;
    virtual google::protobuf::uint8* serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const;
    virtual glodon::objectbuf::EnParseFieldState parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

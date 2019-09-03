#ifndef GFC2POLARAXISGRIDBINARYSERIALIZER_H
#define GFC2POLARAXISGRIDBINARYSERIALIZER_H

#include "Gfc2AxisGridBinarySerializer.h"

class Gfc2PolarAxisGridBinarySerializer: public Gfc2AxisGridBinarySerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2PolarAxisGridBinarySerializer,glodon::objectbuf::EntitySerializer)
public:
    int byteSize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual void serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const;
    virtual google::protobuf::uint8* serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const;
    virtual glodon::objectbuf::EnParseFieldState parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

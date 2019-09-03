#ifndef GFC2HERMITECURVE2DBINARYSERIALIZER_H
#define GFC2HERMITECURVE2DBINARYSERIALIZER_H

#include "Gfc2Curve2dBinarySerializer.h"

class Gfc2HermiteCurve2dBinarySerializer: public Gfc2Curve2dBinarySerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2HermiteCurve2dBinarySerializer,glodon::objectbuf::EntitySerializer)
public:
    int byteSize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual void serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const;
    virtual google::protobuf::uint8* serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const;
    virtual glodon::objectbuf::EnParseFieldState parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

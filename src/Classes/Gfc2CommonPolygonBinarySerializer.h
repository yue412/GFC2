#ifndef GFC2COMMONPOLYGONBINARYSERIALIZER_H
#define GFC2COMMONPOLYGONBINARYSERIALIZER_H

#include "Gfc2PolygonBinarySerializer.h"

class Gfc2CommonPolygonBinarySerializer: public Gfc2PolygonBinarySerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2CommonPolygonBinarySerializer,glodon::objectbuf::EntitySerializer)
public:
    int byteSize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual void serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const;
    virtual google::protobuf::uint8* serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const;
    virtual glodon::objectbuf::EnParseFieldState parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif

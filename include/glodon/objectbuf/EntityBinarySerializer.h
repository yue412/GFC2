#ifndef ENTITYBINARYSERIALIZER_H
#define ENTITYBINARYSERIALIZER_H

#include "EntitySerializer.h"
#include <google/protobuf/io/coded_stream.h>
#include "glodon/objectbuf/Objectbuf.h"

namespace glodon {
namespace objectbuf {

class /*OBJECTBUF_API*/ EntityBinarySerializer : public EntitySerializer
{
public:
    EntityBinarySerializer(void);
    virtual ~EntityBinarySerializer(void);
    bool serialize(google::protobuf::io::CodedOutputStream* output, Entity* pEntity) const;
    virtual bool parse(google::protobuf::io::CodedInputStream* input, Entity* pEntity);
    virtual int byteSize(Entity* pEntity) const;
protected:
    virtual void serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, Entity* pEntity) const;
    virtual google::protobuf::uint8* serializeWithCachedSizesToArray(google::protobuf::uint8* target, Entity* pEntity) const;
    virtual EnParseFieldState parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, Entity* pEntity);
//     void WriteEntityMaybeToArray(int field_number, const Entity& value, google::protobuf::io::CodedOutputStream* output) const;
//     void WriteEntityMaybeToArrayNoTag(const Entity& value, google::protobuf::io::CodedOutputStream* output) const;
//     google::protobuf::uint8* WriteEntityNoVirtualToArray(int field_number, const Entity& value, google::protobuf::uint8* target) const;
//     google::protobuf::uint8* WriteEntityNoVirtualNoTagToArray(const Entity& value, google::protobuf::uint8* target) const;
//     bool ReadEntityNoVirtual(google::protobuf::io::CodedInputStream* input, Entity* value);
};

}
}

#endif

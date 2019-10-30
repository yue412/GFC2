#ifndef ENTITYSCHEMABINARYSERIALIZER_H
#define ENTITYSCHEMABINARYSERIALIZER_H

#include "EntityBinarySerializer.h"
#include "glodon/framework/OBSysMarco.h"


namespace glodon {
namespace objectbuf {

class EntitySchemaBinarySerializer : public EntityBinarySerializer
{
    OBJECTBUF_DEC_OBJECT(EntitySchemaBinarySerializer, EntitySerializer)
public:
    EntitySchemaBinarySerializer(void);
    virtual ~EntitySchemaBinarySerializer(void);
    int byteSize(Entity* pEntity) const;
protected:
    virtual void serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, Entity* pEntity) const;
    virtual google::protobuf::uint8* serializeWithCachedSizesToArray(google::protobuf::uint8* target, Entity* pEntity) const;
    virtual EnParseFieldState parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, Entity* pEntity);
};

}
}

#endif

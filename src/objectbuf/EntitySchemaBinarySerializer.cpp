#include "EntitySchemaBinarySerializer.h"
#include "glodon\objectbuf\EntitySchema.h"
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/stubs/common.h>

namespace glodon {
namespace objectbuf {

OBJECTBUF_IMP_OBJECT(EntitySchemaBinarySerializer, "EntitySchemaB", 0);

EntitySchemaBinarySerializer::EntitySchemaBinarySerializer()
{
}


EntitySchemaBinarySerializer::~EntitySchemaBinarySerializer(void)
{
}

void EntitySchemaBinarySerializer::serializeWithCachedSizes( google::protobuf::io::CodedOutputStream* output, Entity* pEntity) const
{
    EntitySchema* pEnt = (EntitySchema*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasName()) {
        ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(1, pEnt->getName(), output);
    }

    if (pEnt->hasId()) {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getId(), output);
    }

    for (int i = 0; i < pEnt->getAttribNamesCount(); i++) {
        ::google::protobuf::internal::WireFormatLite::WriteString(3, pEnt->getAttribNames(i), output);
    }

    for (int i = 0; i < pEnt->getAttribIdsCount(); i++) {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getAttribIds(i), output);
    }

}

google::protobuf::uint8* EntitySchemaBinarySerializer::serializeWithCachedSizesToArray( google::protobuf::uint8* target, Entity* pEntity ) const
{
    EntitySchema* pEnt = (EntitySchema*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasName()) {
        target = ::google::protobuf::internal::WireFormatLite::WriteStringToArray(1, pEnt->getName(), target);
    }

    if (pEnt->hasId()) {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getId(), target);
    }

    for (int i = 0; i < pEnt->getAttribNamesCount(); i++) {
        target = ::google::protobuf::internal::WireFormatLite::WriteStringToArray(3, pEnt->getAttribNames(i), target);
    }

    for (int i = 0; i < pEnt->getAttribIdsCount(); i++) {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getAttribIds(i), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState EntitySchemaBinarySerializer::parseField( google::protobuf::io::CodedInputStream* input, int nFieldNum, Entity* pEntity )
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    EntitySchema* pEnt = (EntitySchema*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == 1)
    {
        std::string value;
        DO_((google::protobuf::internal::WireFormatLite::ReadString(input, &value)));
        pEnt->setName(value);
        goto success;
    }

    if (nFieldNum == 2)
    {
        int value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<
            google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setId(value);//setHasId();
        goto success;
    }

    if (nFieldNum == 3)
    {
        std::string value;
        DO_((google::protobuf::internal::WireFormatLite::ReadString(input, &value)));
        pEnt->addAttribNames(value);
        goto success;
    }

    if (nFieldNum == 4)
    {
        google::protobuf::int32 value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<
            google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->addAttribIds(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

int EntitySchemaBinarySerializer::byteSize(Entity* pEntity) const
{
    EntitySchema* pEnt = (EntitySchema*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasName()) {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(pEnt->getName());
    }

    if (pEnt->hasId()) {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getId());
    }

    total_size += 1 * pEnt->getAttribNamesCount();
    for (int i = 0; i < pEnt->getAttribNamesCount(); i++) {
        total_size += ::google::protobuf::internal::WireFormatLite::StringSize(pEnt->getAttribNames(i));
    }

    total_size += 1 * pEnt->getAttribIdsCount();
    for (int i = 0; i < pEnt->getAttribIdsCount(); i++) {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getAttribIds(i));
    }

    return total_size;
}


}
}
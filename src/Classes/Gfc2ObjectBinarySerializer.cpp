#include "StdAfx.h"
#include "Gfc2ObjectBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Object.h"

OBJECTBUF_IMP_OBJECT(Gfc2ObjectBinarySerializer,"Gfc2ObjectB",0)

int Gfc2ObjectBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Object* pEnt = (Gfc2Object*)pEntity;
    int total_size = Gfc2RootBinarySerializer::byteSize(pEnt);

    if (pEnt->hasID())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(pEnt->getID());
    }

    if (pEnt->hasName())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getName());
    }

    return total_size;
}

void Gfc2ObjectBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Object* pEnt = (Gfc2Object*)pEntity;
    Gfc2RootBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasID())
    {
        ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(1, pEnt->getID(), output);
    }

    if (pEnt->hasName())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getName(), output);
    }

}

google::protobuf::uint8* Gfc2ObjectBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Object* pEnt = (Gfc2Object*)pEntity;
    target = Gfc2RootBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasID())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteStringToArray(1, pEnt->getID(), target);
    }

    if (pEnt->hasName())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getName(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2ObjectBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Object* pEnt = (Gfc2Object*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2RootBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Object_ID)
    {
        std::string value;
        DO_((google::protobuf::internal::WireFormatLite::ReadString(input, &value)));
        pEnt->setID(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Object_Name)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setName(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


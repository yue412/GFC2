#include "StdAfx.h"
#include "Gfc2FaceShape2dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2FaceShape2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2FaceShape2dBinarySerializer,"Gfc2FaceShape2dB",0)

int Gfc2FaceShape2dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2FaceShape2d* pEnt = (Gfc2FaceShape2d*)pEntity;
    int total_size = Gfc2Shape2dBinarySerializer::byteSize(pEnt);

    if (pEnt->hasPoly())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getPoly());
    }

    return total_size;
}

void Gfc2FaceShape2dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2FaceShape2d* pEnt = (Gfc2FaceShape2d*)pEntity;
    Gfc2Shape2dBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasPoly())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getPoly(), output);
    }

}

google::protobuf::uint8* Gfc2FaceShape2dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2FaceShape2d* pEnt = (Gfc2FaceShape2d*)pEntity;
    target = Gfc2Shape2dBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasPoly())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getPoly(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2FaceShape2dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2FaceShape2d* pEnt = (Gfc2FaceShape2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Shape2dBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2FaceShape2d_Poly)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setPoly(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


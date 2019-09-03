#include "StdAfx.h"
#include "Gfc2Coordinates2dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Coordinates2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2Coordinates2dBinarySerializer,"Gfc2Coordinates2dB",0)

int Gfc2Coordinates2dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Coordinates2d* pEnt = (Gfc2Coordinates2d*)pEntity;
    int total_size = Gfc2GeometryBinarySerializer::byteSize(pEnt);

    if (pEnt->hasOrigin())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getOrigin());
    }

    if (pEnt->hasX())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getX());
    }

    if (pEnt->hasY())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getY());
    }

    return total_size;
}

void Gfc2Coordinates2dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Coordinates2d* pEnt = (Gfc2Coordinates2d*)pEntity;
    Gfc2GeometryBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasOrigin())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getOrigin(), output);
    }

    if (pEnt->hasX())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getX(), output);
    }

    if (pEnt->hasY())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getY(), output);
    }

}

google::protobuf::uint8* Gfc2Coordinates2dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Coordinates2d* pEnt = (Gfc2Coordinates2d*)pEntity;
    target = Gfc2GeometryBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasOrigin())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getOrigin(), target);
    }

    if (pEnt->hasX())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getX(), target);
    }

    if (pEnt->hasY())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getY(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2Coordinates2dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Coordinates2d* pEnt = (Gfc2Coordinates2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2GeometryBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Coordinates2d_Origin)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setOrigin(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Coordinates2d_X)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setX(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Coordinates2d_Y)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setY(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


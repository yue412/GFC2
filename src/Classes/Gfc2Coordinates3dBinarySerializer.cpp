#include "StdAfx.h"
#include "Gfc2Coordinates3dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Coordinates3d.h"

OBJECTBUF_IMP_OBJECT(Gfc2Coordinates3dBinarySerializer,"Gfc2Coordinates3dB",0)

int Gfc2Coordinates3dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Coordinates3d* pEnt = (Gfc2Coordinates3d*)pEntity;
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

    if (pEnt->hasZ())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getZ());
    }

    return total_size;
}

void Gfc2Coordinates3dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Coordinates3d* pEnt = (Gfc2Coordinates3d*)pEntity;
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

    if (pEnt->hasZ())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getZ(), output);
    }

}

google::protobuf::uint8* Gfc2Coordinates3dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Coordinates3d* pEnt = (Gfc2Coordinates3d*)pEntity;
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

    if (pEnt->hasZ())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getZ(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2Coordinates3dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Coordinates3d* pEnt = (Gfc2Coordinates3d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2GeometryBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Coordinates3d_Origin)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setOrigin(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Coordinates3d_X)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setX(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Coordinates3d_Y)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setY(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Coordinates3d_Z)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setZ(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


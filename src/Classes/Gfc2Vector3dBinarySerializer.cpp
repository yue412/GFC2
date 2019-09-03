#include "StdAfx.h"
#include "Gfc2Vector3dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Vector3d.h"

OBJECTBUF_IMP_OBJECT(Gfc2Vector3dBinarySerializer,"Gfc2Vector3dB",0)

int Gfc2Vector3dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Vector3d* pEnt = (Gfc2Vector3d*)pEntity;
    int total_size = Gfc2GeometryBinarySerializer::byteSize(pEnt);

    if (pEnt->hasX())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasY())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasZ())
    {
        total_size += 1 + 8;
    }

    return total_size;
}

void Gfc2Vector3dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Vector3d* pEnt = (Gfc2Vector3d*)pEntity;
    Gfc2GeometryBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasX())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(1, pEnt->getX(), output);
    }

    if (pEnt->hasY())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(2, pEnt->getY(), output);
    }

    if (pEnt->hasZ())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(3, pEnt->getZ(), output);
    }

}

google::protobuf::uint8* Gfc2Vector3dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Vector3d* pEnt = (Gfc2Vector3d*)pEntity;
    target = Gfc2GeometryBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasX())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, pEnt->getX(), target);
    }

    if (pEnt->hasY())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, pEnt->getY(), target);
    }

    if (pEnt->hasZ())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, pEnt->getZ(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2Vector3dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Vector3d* pEnt = (Gfc2Vector3d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2GeometryBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Vector3d_X)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setX(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Vector3d_Y)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setY(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Vector3d_Z)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
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


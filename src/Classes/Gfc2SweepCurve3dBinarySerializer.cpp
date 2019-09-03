#include "StdAfx.h"
#include "Gfc2SweepCurve3dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2SweepCurve3d.h"

OBJECTBUF_IMP_OBJECT(Gfc2SweepCurve3dBinarySerializer,"Gfc2SweepCurve3dB",0)

int Gfc2SweepCurve3dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SweepCurve3d* pEnt = (Gfc2SweepCurve3d*)pEntity;
    int total_size = Gfc2Curve3dBinarySerializer::byteSize(pEnt);

    if (pEnt->hasSpine3d())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getSpine3d());
    }

    if (pEnt->hasReferenceVector())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getReferenceVector());
    }

    if (pEnt->hasPoint())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getPoint());
    }

    return total_size;
}

void Gfc2SweepCurve3dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SweepCurve3d* pEnt = (Gfc2SweepCurve3d*)pEntity;
    Gfc2Curve3dBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasSpine3d())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getSpine3d(), output);
    }

    if (pEnt->hasReferenceVector())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getReferenceVector(), output);
    }

    if (pEnt->hasPoint())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getPoint(), output);
    }

}

google::protobuf::uint8* Gfc2SweepCurve3dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SweepCurve3d* pEnt = (Gfc2SweepCurve3d*)pEntity;
    target = Gfc2Curve3dBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasSpine3d())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getSpine3d(), target);
    }

    if (pEnt->hasReferenceVector())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getReferenceVector(), target);
    }

    if (pEnt->hasPoint())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getPoint(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2SweepCurve3dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SweepCurve3d* pEnt = (Gfc2SweepCurve3d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve3dBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2SweepCurve3d_Spine3d)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setSpine3d(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SweepCurve3d_ReferenceVector)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setReferenceVector(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SweepCurve3d_Point)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setPoint(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


#include "StdAfx.h"
#include "Gfc2SweepBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Sweep.h"

OBJECTBUF_IMP_OBJECT(Gfc2SweepBinarySerializer,"Gfc2SweepB",0)

int Gfc2SweepBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Sweep* pEnt = (Gfc2Sweep*)pEntity;
    int total_size = Gfc2SurfaceBinarySerializer::byteSize(pEnt);

    if (pEnt->hasProfile())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getProfile());
    }

    if (pEnt->hasSpine3d())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getSpine3d());
    }

    if (pEnt->hasReferenceVector())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getReferenceVector());
    }

    return total_size;
}

void Gfc2SweepBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Sweep* pEnt = (Gfc2Sweep*)pEntity;
    Gfc2SurfaceBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasProfile())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getProfile(), output);
    }

    if (pEnt->hasSpine3d())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getSpine3d(), output);
    }

    if (pEnt->hasReferenceVector())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getReferenceVector(), output);
    }

}

google::protobuf::uint8* Gfc2SweepBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Sweep* pEnt = (Gfc2Sweep*)pEntity;
    target = Gfc2SurfaceBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasProfile())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getProfile(), target);
    }

    if (pEnt->hasSpine3d())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getSpine3d(), target);
    }

    if (pEnt->hasReferenceVector())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getReferenceVector(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2SweepBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Sweep* pEnt = (Gfc2Sweep*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SurfaceBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Sweep_Profile)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setProfile(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Sweep_Spine3d)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setSpine3d(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Sweep_ReferenceVector)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setReferenceVector(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


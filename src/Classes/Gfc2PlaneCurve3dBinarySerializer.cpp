#include "StdAfx.h"
#include "Gfc2PlaneCurve3dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2PlaneCurve3d.h"

OBJECTBUF_IMP_OBJECT(Gfc2PlaneCurve3dBinarySerializer,"Gfc2PlaneCurve3dB",0)

int Gfc2PlaneCurve3dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PlaneCurve3d* pEnt = (Gfc2PlaneCurve3d*)pEntity;
    int total_size = Gfc2Curve3dBinarySerializer::byteSize(pEnt);

    if (pEnt->hasPlaneCurve())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getPlaneCurve());
    }

    if (pEnt->hasPlane())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getPlane());
    }

    return total_size;
}

void Gfc2PlaneCurve3dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PlaneCurve3d* pEnt = (Gfc2PlaneCurve3d*)pEntity;
    Gfc2Curve3dBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasPlaneCurve())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getPlaneCurve(), output);
    }

    if (pEnt->hasPlane())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getPlane(), output);
    }

}

google::protobuf::uint8* Gfc2PlaneCurve3dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PlaneCurve3d* pEnt = (Gfc2PlaneCurve3d*)pEntity;
    target = Gfc2Curve3dBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasPlaneCurve())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getPlaneCurve(), target);
    }

    if (pEnt->hasPlane())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getPlane(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2PlaneCurve3dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PlaneCurve3d* pEnt = (Gfc2PlaneCurve3d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve3dBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2PlaneCurve3d_PlaneCurve)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setPlaneCurve(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PlaneCurve3d_Plane)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setPlane(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


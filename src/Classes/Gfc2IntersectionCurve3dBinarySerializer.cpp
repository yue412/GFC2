#include "StdAfx.h"
#include "Gfc2IntersectionCurve3dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2IntersectionCurve3d.h"

OBJECTBUF_IMP_OBJECT(Gfc2IntersectionCurve3dBinarySerializer,"Gfc2IntersectionCurve3dB",0)

int Gfc2IntersectionCurve3dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2IntersectionCurve3d* pEnt = (Gfc2IntersectionCurve3d*)pEntity;
    int total_size = Gfc2Curve3dBinarySerializer::byteSize(pEnt);

    if (pEnt->hasBases1())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getBases1());
    }

    if (pEnt->hasBases2())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getBases2());
    }

    if (pEnt->hasRange())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRange());
    }

    if (pEnt->hasChart())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getChart());
    }

    return total_size;
}

void Gfc2IntersectionCurve3dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2IntersectionCurve3d* pEnt = (Gfc2IntersectionCurve3d*)pEntity;
    Gfc2Curve3dBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasBases1())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getBases1(), output);
    }

    if (pEnt->hasBases2())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getBases2(), output);
    }

    if (pEnt->hasRange())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getRange(), output);
    }

    if (pEnt->hasChart())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getChart(), output);
    }

}

google::protobuf::uint8* Gfc2IntersectionCurve3dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2IntersectionCurve3d* pEnt = (Gfc2IntersectionCurve3d*)pEntity;
    target = Gfc2Curve3dBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasBases1())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getBases1(), target);
    }

    if (pEnt->hasBases2())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getBases2(), target);
    }

    if (pEnt->hasRange())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getRange(), target);
    }

    if (pEnt->hasChart())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getChart(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2IntersectionCurve3dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2IntersectionCurve3d* pEnt = (Gfc2IntersectionCurve3d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve3dBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2IntersectionCurve3d_Bases1)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setBases1(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2IntersectionCurve3d_Bases2)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setBases2(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2IntersectionCurve3d_Range)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRange(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2IntersectionCurve3d_Chart)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setChart(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


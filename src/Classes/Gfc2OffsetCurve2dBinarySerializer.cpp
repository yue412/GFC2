#include "StdAfx.h"
#include "Gfc2OffsetCurve2dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2OffsetCurve2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2OffsetCurve2dBinarySerializer,"Gfc2OffsetCurve2dB",0)

int Gfc2OffsetCurve2dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2OffsetCurve2d* pEnt = (Gfc2OffsetCurve2d*)pEntity;
    int total_size = Gfc2Curve2dBinarySerializer::byteSize(pEnt);

    if (pEnt->hasOffDist())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasInitCurve())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getInitCurve());
    }

    return total_size;
}

void Gfc2OffsetCurve2dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2OffsetCurve2d* pEnt = (Gfc2OffsetCurve2d*)pEntity;
    Gfc2Curve2dBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasOffDist())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(1, pEnt->getOffDist(), output);
    }

    if (pEnt->hasInitCurve())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getInitCurve(), output);
    }

}

google::protobuf::uint8* Gfc2OffsetCurve2dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2OffsetCurve2d* pEnt = (Gfc2OffsetCurve2d*)pEntity;
    target = Gfc2Curve2dBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasOffDist())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, pEnt->getOffDist(), target);
    }

    if (pEnt->hasInitCurve())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getInitCurve(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2OffsetCurve2dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2OffsetCurve2d* pEnt = (Gfc2OffsetCurve2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve2dBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2OffsetCurve2d_OffDist)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setOffDist(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2OffsetCurve2d_InitCurve)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setInitCurve(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


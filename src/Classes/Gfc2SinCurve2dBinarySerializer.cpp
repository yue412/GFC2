#include "StdAfx.h"
#include "Gfc2SinCurve2dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2SinCurve2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2SinCurve2dBinarySerializer,"Gfc2SinCurve2dB",0)

int Gfc2SinCurve2dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SinCurve2d* pEnt = (Gfc2SinCurve2d*)pEntity;
    int total_size = Gfc2Curve2dBinarySerializer::byteSize(pEnt);

    if (pEnt->hasPos())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getPos());
    }

    if (pEnt->hasDirX())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDirX());
    }

    if (pEnt->hasA())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasB())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasRange())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRange());
    }

    if (pEnt->hasClockSign())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getClockSign());
    }

    return total_size;
}

void Gfc2SinCurve2dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SinCurve2d* pEnt = (Gfc2SinCurve2d*)pEntity;
    Gfc2Curve2dBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasPos())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getPos(), output);
    }

    if (pEnt->hasDirX())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getDirX(), output);
    }

    if (pEnt->hasA())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(3, pEnt->getA(), output);
    }

    if (pEnt->hasB())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(4, pEnt->getB(), output);
    }

    if (pEnt->hasRange())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(5, pEnt->getRange(), output);
    }

    if (pEnt->hasClockSign())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(6, pEnt->getClockSign(), output);
    }

}

google::protobuf::uint8* Gfc2SinCurve2dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SinCurve2d* pEnt = (Gfc2SinCurve2d*)pEntity;
    target = Gfc2Curve2dBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasPos())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getPos(), target);
    }

    if (pEnt->hasDirX())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getDirX(), target);
    }

    if (pEnt->hasA())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, pEnt->getA(), target);
    }

    if (pEnt->hasB())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, pEnt->getB(), target);
    }

    if (pEnt->hasRange())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, pEnt->getRange(), target);
    }

    if (pEnt->hasClockSign())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, pEnt->getClockSign(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2SinCurve2dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SinCurve2d* pEnt = (Gfc2SinCurve2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve2dBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2SinCurve2d_Pos)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setPos(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SinCurve2d_DirX)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDirX(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SinCurve2d_A)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setA(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SinCurve2d_B)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setB(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SinCurve2d_Range)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRange(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SinCurve2d_ClockSign)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setClockSign(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


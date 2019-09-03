#include "StdAfx.h"
#include "Gfc2PreimageCurve2dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2PreimageCurve2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2PreimageCurve2dBinarySerializer,"Gfc2PreimageCurve2dB",0)

int Gfc2PreimageCurve2dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PreimageCurve2d* pEnt = (Gfc2PreimageCurve2d*)pEntity;
    int total_size = Gfc2Curve2dBinarySerializer::byteSize(pEnt);

    if (pEnt->hasRange())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRange());
    }

    if (pEnt->hasReversed())
    {
        total_size += 1 + 1;
    }

    if (pEnt->hasBase())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getBase());
    }

    if (pEnt->hasCurve())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCurve());
    }

    if (pEnt->hasTolerance())
    {
        total_size += 1 + 8;
    }

    return total_size;
}

void Gfc2PreimageCurve2dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PreimageCurve2d* pEnt = (Gfc2PreimageCurve2d*)pEntity;
    Gfc2Curve2dBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasRange())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getRange(), output);
    }

    if (pEnt->hasReversed())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(2, pEnt->getReversed(), output);
    }

    if (pEnt->hasBase())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getBase(), output);
    }

    if (pEnt->hasCurve())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getCurve(), output);
    }

    if (pEnt->hasTolerance())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(5, pEnt->getTolerance(), output);
    }

}

google::protobuf::uint8* Gfc2PreimageCurve2dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PreimageCurve2d* pEnt = (Gfc2PreimageCurve2d*)pEntity;
    target = Gfc2Curve2dBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasRange())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getRange(), target);
    }

    if (pEnt->hasReversed())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, pEnt->getReversed(), target);
    }

    if (pEnt->hasBase())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getBase(), target);
    }

    if (pEnt->hasCurve())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getCurve(), target);
    }

    if (pEnt->hasTolerance())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(5, pEnt->getTolerance(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2PreimageCurve2dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PreimageCurve2d* pEnt = (Gfc2PreimageCurve2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve2dBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2PreimageCurve2d_Range)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRange(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PreimageCurve2d_Reversed)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setReversed(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PreimageCurve2d_Base)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setBase(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PreimageCurve2d_Curve)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCurve(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PreimageCurve2d_Tolerance)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setTolerance(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


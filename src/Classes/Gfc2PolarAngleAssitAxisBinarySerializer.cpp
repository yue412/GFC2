#include "StdAfx.h"
#include "Gfc2PolarAngleAssitAxisBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2PolarAngleAssitAxis.h"

OBJECTBUF_IMP_OBJECT(Gfc2PolarAngleAssitAxisBinarySerializer,"Gfc2PolarAngleAssitAxisB",0)

int Gfc2PolarAngleAssitAxisBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PolarAngleAssitAxis* pEnt = (Gfc2PolarAngleAssitAxis*)pEntity;
    int total_size = Gfc2AssitAxisBinarySerializer::byteSize(pEnt);

    if (pEnt->hasRefAxisNo())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRefAxisNo());
    }

    if (pEnt->hasAngle())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasRefAxisIndex())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRefAxisIndex());
    }

    return total_size;
}

void Gfc2PolarAngleAssitAxisBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PolarAngleAssitAxis* pEnt = (Gfc2PolarAngleAssitAxis*)pEntity;
    Gfc2AssitAxisBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasRefAxisNo())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(9, pEnt->getRefAxisNo(), output);
    }

    if (pEnt->hasAngle())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(10, pEnt->getAngle(), output);
    }

    if (pEnt->hasRefAxisIndex())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(11, pEnt->getRefAxisIndex(), output);
    }

}

google::protobuf::uint8* Gfc2PolarAngleAssitAxisBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PolarAngleAssitAxis* pEnt = (Gfc2PolarAngleAssitAxis*)pEntity;
    target = Gfc2AssitAxisBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasRefAxisNo())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, pEnt->getRefAxisNo(), target);
    }

    if (pEnt->hasAngle())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(10, pEnt->getAngle(), target);
    }

    if (pEnt->hasRefAxisIndex())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(11, pEnt->getRefAxisIndex(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2PolarAngleAssitAxisBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PolarAngleAssitAxis* pEnt = (Gfc2PolarAngleAssitAxis*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2AssitAxisBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2PolarAngleAssitAxis_RefAxisNo)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRefAxisNo(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PolarAngleAssitAxis_Angle)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setAngle(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PolarAngleAssitAxis_RefAxisIndex)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRefAxisIndex(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


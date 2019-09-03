#include "StdAfx.h"
#include "Gfc2AxisAngleAssitAxisBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2AxisAngleAssitAxis.h"

OBJECTBUF_IMP_OBJECT(Gfc2AxisAngleAssitAxisBinarySerializer,"Gfc2AxisAngleAssitAxisB",0)

int Gfc2AxisAngleAssitAxisBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2AxisAngleAssitAxis* pEnt = (Gfc2AxisAngleAssitAxis*)pEntity;
    int total_size = Gfc2AssitAxisBinarySerializer::byteSize(pEnt);

    if (pEnt->hasRefAxisNo())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRefAxisNo());
    }

    if (pEnt->hasRefPoint())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRefPoint());
    }

    if (pEnt->hasAngle())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasRefAxisIndex())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRefAxisIndex());
    }

    if (pEnt->hasRefAxisType())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size((int)pEnt->getRefAxisType());
    }

    return total_size;
}

void Gfc2AxisAngleAssitAxisBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2AxisAngleAssitAxis* pEnt = (Gfc2AxisAngleAssitAxis*)pEntity;
    Gfc2AssitAxisBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasRefAxisNo())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(9, pEnt->getRefAxisNo(), output);
    }

    if (pEnt->hasRefPoint())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(10, pEnt->getRefPoint(), output);
    }

    if (pEnt->hasAngle())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(11, pEnt->getAngle(), output);
    }

    if (pEnt->hasRefAxisIndex())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(12, pEnt->getRefAxisIndex(), output);
    }

    if (pEnt->hasRefAxisType())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(13, (int)pEnt->getRefAxisType(), output);
    }

}

google::protobuf::uint8* Gfc2AxisAngleAssitAxisBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2AxisAngleAssitAxis* pEnt = (Gfc2AxisAngleAssitAxis*)pEntity;
    target = Gfc2AssitAxisBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasRefAxisNo())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, pEnt->getRefAxisNo(), target);
    }

    if (pEnt->hasRefPoint())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(10, pEnt->getRefPoint(), target);
    }

    if (pEnt->hasAngle())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(11, pEnt->getAngle(), target);
    }

    if (pEnt->hasRefAxisIndex())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(12, pEnt->getRefAxisIndex(), target);
    }

    if (pEnt->hasRefAxisType())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(13, (int)pEnt->getRefAxisType(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2AxisAngleAssitAxisBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2AxisAngleAssitAxis* pEnt = (Gfc2AxisAngleAssitAxis*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2AssitAxisBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2AxisAngleAssitAxis_RefAxisNo)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRefAxisNo(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AxisAngleAssitAxis_RefPoint)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRefPoint(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AxisAngleAssitAxis_Angle)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setAngle(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AxisAngleAssitAxis_RefAxisIndex)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRefAxisIndex(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AxisAngleAssitAxis_RefAxisType)
    {
        Gfc2AxisType value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, (google::protobuf::int32*)&value)));
        pEnt->setRefAxisType(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


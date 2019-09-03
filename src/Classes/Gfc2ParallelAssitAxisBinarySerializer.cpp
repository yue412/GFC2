#include "StdAfx.h"
#include "Gfc2ParallelAssitAxisBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2ParallelAssitAxis.h"

OBJECTBUF_IMP_OBJECT(Gfc2ParallelAssitAxisBinarySerializer,"Gfc2ParallelAssitAxisB",0)

int Gfc2ParallelAssitAxisBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2ParallelAssitAxis* pEnt = (Gfc2ParallelAssitAxis*)pEntity;
    int total_size = Gfc2AssitAxisBinarySerializer::byteSize(pEnt);

    if (pEnt->hasRefAxisNo())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRefAxisNo());
    }

    if (pEnt->hasOffset())
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

void Gfc2ParallelAssitAxisBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2ParallelAssitAxis* pEnt = (Gfc2ParallelAssitAxis*)pEntity;
    Gfc2AssitAxisBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasRefAxisNo())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(9, pEnt->getRefAxisNo(), output);
    }

    if (pEnt->hasOffset())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(10, pEnt->getOffset(), output);
    }

    if (pEnt->hasRefAxisIndex())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(11, pEnt->getRefAxisIndex(), output);
    }

    if (pEnt->hasRefAxisType())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(12, (int)pEnt->getRefAxisType(), output);
    }

}

google::protobuf::uint8* Gfc2ParallelAssitAxisBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2ParallelAssitAxis* pEnt = (Gfc2ParallelAssitAxis*)pEntity;
    target = Gfc2AssitAxisBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasRefAxisNo())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, pEnt->getRefAxisNo(), target);
    }

    if (pEnt->hasOffset())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(10, pEnt->getOffset(), target);
    }

    if (pEnt->hasRefAxisIndex())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(11, pEnt->getRefAxisIndex(), target);
    }

    if (pEnt->hasRefAxisType())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(12, (int)pEnt->getRefAxisType(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2ParallelAssitAxisBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2ParallelAssitAxis* pEnt = (Gfc2ParallelAssitAxis*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2AssitAxisBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2ParallelAssitAxis_RefAxisNo)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRefAxisNo(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2ParallelAssitAxis_Offset)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setOffset(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2ParallelAssitAxis_RefAxisIndex)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRefAxisIndex(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2ParallelAssitAxis_RefAxisType)
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


#include "StdAfx.h"
#include "Gfc2PointAngleAssitAxisBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2PointAngleAssitAxis.h"

OBJECTBUF_IMP_OBJECT(Gfc2PointAngleAssitAxisBinarySerializer,"Gfc2PointAngleAssitAxisB",0)

int Gfc2PointAngleAssitAxisBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PointAngleAssitAxis* pEnt = (Gfc2PointAngleAssitAxis*)pEntity;
    int total_size = Gfc2AssitAxisBinarySerializer::byteSize(pEnt);

    if (pEnt->hasRefPoint())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRefPoint());
    }

    if (pEnt->hasAngle())
    {
        total_size += 1 + 8;
    }

    return total_size;
}

void Gfc2PointAngleAssitAxisBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PointAngleAssitAxis* pEnt = (Gfc2PointAngleAssitAxis*)pEntity;
    Gfc2AssitAxisBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasRefPoint())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(9, pEnt->getRefPoint(), output);
    }

    if (pEnt->hasAngle())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(10, pEnt->getAngle(), output);
    }

}

google::protobuf::uint8* Gfc2PointAngleAssitAxisBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PointAngleAssitAxis* pEnt = (Gfc2PointAngleAssitAxis*)pEntity;
    target = Gfc2AssitAxisBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasRefPoint())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, pEnt->getRefPoint(), target);
    }

    if (pEnt->hasAngle())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(10, pEnt->getAngle(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2PointAngleAssitAxisBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PointAngleAssitAxis* pEnt = (Gfc2PointAngleAssitAxis*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2AssitAxisBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2PointAngleAssitAxis_RefPoint)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRefPoint(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PointAngleAssitAxis_Angle)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setAngle(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


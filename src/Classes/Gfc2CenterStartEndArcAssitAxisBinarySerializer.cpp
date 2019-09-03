#include "StdAfx.h"
#include "Gfc2CenterStartEndArcAssitAxisBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2CenterStartEndArcAssitAxis.h"

OBJECTBUF_IMP_OBJECT(Gfc2CenterStartEndArcAssitAxisBinarySerializer,"Gfc2CenterStartEndArcAssitAxisB",0)

int Gfc2CenterStartEndArcAssitAxisBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CenterStartEndArcAssitAxis* pEnt = (Gfc2CenterStartEndArcAssitAxis*)pEntity;
    int total_size = Gfc2AssitAxisBinarySerializer::byteSize(pEnt);

    if (pEnt->hasCenter())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCenter());
    }

    if (pEnt->hasStartPoint())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getStartPoint());
    }

    if (pEnt->hasEndPoint())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getEndPoint());
    }

    return total_size;
}

void Gfc2CenterStartEndArcAssitAxisBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CenterStartEndArcAssitAxis* pEnt = (Gfc2CenterStartEndArcAssitAxis*)pEntity;
    Gfc2AssitAxisBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasCenter())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(9, pEnt->getCenter(), output);
    }

    if (pEnt->hasStartPoint())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(10, pEnt->getStartPoint(), output);
    }

    if (pEnt->hasEndPoint())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(11, pEnt->getEndPoint(), output);
    }

}

google::protobuf::uint8* Gfc2CenterStartEndArcAssitAxisBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CenterStartEndArcAssitAxis* pEnt = (Gfc2CenterStartEndArcAssitAxis*)pEntity;
    target = Gfc2AssitAxisBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasCenter())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, pEnt->getCenter(), target);
    }

    if (pEnt->hasStartPoint())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(10, pEnt->getStartPoint(), target);
    }

    if (pEnt->hasEndPoint())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(11, pEnt->getEndPoint(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2CenterStartEndArcAssitAxisBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CenterStartEndArcAssitAxis* pEnt = (Gfc2CenterStartEndArcAssitAxis*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2AssitAxisBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2CenterStartEndArcAssitAxis_Center)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCenter(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2CenterStartEndArcAssitAxis_StartPoint)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setStartPoint(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2CenterStartEndArcAssitAxis_EndPoint)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setEndPoint(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


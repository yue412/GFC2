#include "StdAfx.h"
#include "Gfc2CircleAssitAxisBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2CircleAssitAxis.h"

OBJECTBUF_IMP_OBJECT(Gfc2CircleAssitAxisBinarySerializer,"Gfc2CircleAssitAxisB",0)

int Gfc2CircleAssitAxisBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CircleAssitAxis* pEnt = (Gfc2CircleAssitAxis*)pEntity;
    int total_size = Gfc2AssitAxisBinarySerializer::byteSize(pEnt);

    if (pEnt->hasCenter())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCenter());
    }

    if (pEnt->hasRadius())
    {
        total_size += 1 + 8;
    }

    return total_size;
}

void Gfc2CircleAssitAxisBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CircleAssitAxis* pEnt = (Gfc2CircleAssitAxis*)pEntity;
    Gfc2AssitAxisBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasCenter())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(9, pEnt->getCenter(), output);
    }

    if (pEnt->hasRadius())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(10, pEnt->getRadius(), output);
    }

}

google::protobuf::uint8* Gfc2CircleAssitAxisBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CircleAssitAxis* pEnt = (Gfc2CircleAssitAxis*)pEntity;
    target = Gfc2AssitAxisBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasCenter())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, pEnt->getCenter(), target);
    }

    if (pEnt->hasRadius())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(10, pEnt->getRadius(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2CircleAssitAxisBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CircleAssitAxis* pEnt = (Gfc2CircleAssitAxis*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2AssitAxisBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2CircleAssitAxis_Center)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCenter(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2CircleAssitAxis_Radius)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setRadius(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


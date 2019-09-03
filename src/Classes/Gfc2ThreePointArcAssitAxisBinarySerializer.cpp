#include "StdAfx.h"
#include "Gfc2ThreePointArcAssitAxisBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2ThreePointArcAssitAxis.h"

OBJECTBUF_IMP_OBJECT(Gfc2ThreePointArcAssitAxisBinarySerializer,"Gfc2ThreePointArcAssitAxisB",0)

int Gfc2ThreePointArcAssitAxisBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2ThreePointArcAssitAxis* pEnt = (Gfc2ThreePointArcAssitAxis*)pEntity;
    int total_size = Gfc2AssitAxisBinarySerializer::byteSize(pEnt);

    if (pEnt->hasRefPoint1())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRefPoint1());
    }

    if (pEnt->hasRefPoint2())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRefPoint2());
    }

    if (pEnt->hasRefPoint3())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRefPoint3());
    }

    return total_size;
}

void Gfc2ThreePointArcAssitAxisBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2ThreePointArcAssitAxis* pEnt = (Gfc2ThreePointArcAssitAxis*)pEntity;
    Gfc2AssitAxisBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasRefPoint1())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(9, pEnt->getRefPoint1(), output);
    }

    if (pEnt->hasRefPoint2())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(10, pEnt->getRefPoint2(), output);
    }

    if (pEnt->hasRefPoint3())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(11, pEnt->getRefPoint3(), output);
    }

}

google::protobuf::uint8* Gfc2ThreePointArcAssitAxisBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2ThreePointArcAssitAxis* pEnt = (Gfc2ThreePointArcAssitAxis*)pEntity;
    target = Gfc2AssitAxisBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasRefPoint1())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, pEnt->getRefPoint1(), target);
    }

    if (pEnt->hasRefPoint2())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(10, pEnt->getRefPoint2(), target);
    }

    if (pEnt->hasRefPoint3())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(11, pEnt->getRefPoint3(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2ThreePointArcAssitAxisBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2ThreePointArcAssitAxis* pEnt = (Gfc2ThreePointArcAssitAxis*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2AssitAxisBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2ThreePointArcAssitAxis_RefPoint1)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRefPoint1(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2ThreePointArcAssitAxis_RefPoint2)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRefPoint2(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2ThreePointArcAssitAxis_RefPoint3)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRefPoint3(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


#include "StdAfx.h"
#include "Gfc2ShapeBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Shape.h"

OBJECTBUF_IMP_OBJECT(Gfc2ShapeBinarySerializer,"Gfc2ShapeB",0)

int Gfc2ShapeBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Shape* pEnt = (Gfc2Shape*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasLocalCoordinate())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLocalCoordinate());
    }

    if (pEnt->hasBoundingBox())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getBoundingBox());
    }

    return total_size;
}

void Gfc2ShapeBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Shape* pEnt = (Gfc2Shape*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasLocalCoordinate())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getLocalCoordinate(), output);
    }

    if (pEnt->hasBoundingBox())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getBoundingBox(), output);
    }

}

google::protobuf::uint8* Gfc2ShapeBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Shape* pEnt = (Gfc2Shape*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasLocalCoordinate())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getLocalCoordinate(), target);
    }

    if (pEnt->hasBoundingBox())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getBoundingBox(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2ShapeBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Shape* pEnt = (Gfc2Shape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Shape_LocalCoordinate)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setLocalCoordinate(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Shape_BoundingBox)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setBoundingBox(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


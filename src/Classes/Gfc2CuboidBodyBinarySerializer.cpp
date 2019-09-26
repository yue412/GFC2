#include "StdAfx.h"
#include "Gfc2CuboidBodyBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2CuboidBody.h"

OBJECTBUF_IMP_OBJECT(Gfc2CuboidBodyBinarySerializer,"Gfc2CuboidBodyB",0)

int Gfc2CuboidBodyBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CuboidBody* pEnt = (Gfc2CuboidBody*)pEntity;
    int total_size = Gfc2PrimitiveBodyBinarySerializer::byteSize(pEnt);

    if (pEnt->hasCoordinate())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCoordinate());
    }

    if (pEnt->hasDimension())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDimension());
    }

    return total_size;
}

void Gfc2CuboidBodyBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CuboidBody* pEnt = (Gfc2CuboidBody*)pEntity;
    Gfc2PrimitiveBodyBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasCoordinate())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getCoordinate(), output);
    }

    if (pEnt->hasDimension())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getDimension(), output);
    }

}

google::protobuf::uint8* Gfc2CuboidBodyBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CuboidBody* pEnt = (Gfc2CuboidBody*)pEntity;
    target = Gfc2PrimitiveBodyBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasCoordinate())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getCoordinate(), target);
    }

    if (pEnt->hasDimension())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getDimension(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2CuboidBodyBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CuboidBody* pEnt = (Gfc2CuboidBody*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2PrimitiveBodyBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2CuboidBody_Coordinate)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCoordinate(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2CuboidBody_Dimension)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDimension(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


#include "StdAfx.h"
#include "Gfc2PlaneInfoBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2PlaneInfo.h"

OBJECTBUF_IMP_OBJECT(Gfc2PlaneInfoBinarySerializer,"Gfc2PlaneInfoB",0)

int Gfc2PlaneInfoBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PlaneInfo* pEnt = (Gfc2PlaneInfo*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasDirX())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDirX());
    }

    if (pEnt->hasDirY())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDirY());
    }

    if (pEnt->hasPos())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getPos());
    }

    return total_size;
}

void Gfc2PlaneInfoBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PlaneInfo* pEnt = (Gfc2PlaneInfo*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasDirX())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getDirX(), output);
    }

    if (pEnt->hasDirY())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getDirY(), output);
    }

    if (pEnt->hasPos())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getPos(), output);
    }

}

google::protobuf::uint8* Gfc2PlaneInfoBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PlaneInfo* pEnt = (Gfc2PlaneInfo*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasDirX())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getDirX(), target);
    }

    if (pEnt->hasDirY())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getDirY(), target);
    }

    if (pEnt->hasPos())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getPos(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2PlaneInfoBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PlaneInfo* pEnt = (Gfc2PlaneInfo*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2PlaneInfo_DirX)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDirX(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PlaneInfo_DirY)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDirY(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PlaneInfo_Pos)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setPos(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


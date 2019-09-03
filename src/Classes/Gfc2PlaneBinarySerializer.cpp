#include "StdAfx.h"
#include "Gfc2PlaneBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Plane.h"

OBJECTBUF_IMP_OBJECT(Gfc2PlaneBinarySerializer,"Gfc2PlaneB",0)

int Gfc2PlaneBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Plane* pEnt = (Gfc2Plane*)pEntity;
    int total_size = Gfc2SurfaceBinarySerializer::byteSize(pEnt);

    if (pEnt->hasPos())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getPos());
    }

    if (pEnt->hasDirU())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDirU());
    }

    if (pEnt->hasDirV())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDirV());
    }

    if (pEnt->hasRangeU())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRangeU());
    }

    if (pEnt->hasRangeV())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRangeV());
    }

    return total_size;
}

void Gfc2PlaneBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Plane* pEnt = (Gfc2Plane*)pEntity;
    Gfc2SurfaceBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasPos())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getPos(), output);
    }

    if (pEnt->hasDirU())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getDirU(), output);
    }

    if (pEnt->hasDirV())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getDirV(), output);
    }

    if (pEnt->hasRangeU())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getRangeU(), output);
    }

    if (pEnt->hasRangeV())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(5, pEnt->getRangeV(), output);
    }

}

google::protobuf::uint8* Gfc2PlaneBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Plane* pEnt = (Gfc2Plane*)pEntity;
    target = Gfc2SurfaceBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasPos())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getPos(), target);
    }

    if (pEnt->hasDirU())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getDirU(), target);
    }

    if (pEnt->hasDirV())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getDirV(), target);
    }

    if (pEnt->hasRangeU())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getRangeU(), target);
    }

    if (pEnt->hasRangeV())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, pEnt->getRangeV(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2PlaneBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Plane* pEnt = (Gfc2Plane*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SurfaceBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Plane_Pos)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setPos(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Plane_DirU)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDirU(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Plane_DirV)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDirV(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Plane_RangeU)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRangeU(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Plane_RangeV)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRangeV(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


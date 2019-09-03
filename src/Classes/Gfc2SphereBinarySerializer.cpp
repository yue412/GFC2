#include "StdAfx.h"
#include "Gfc2SphereBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Sphere.h"

OBJECTBUF_IMP_OBJECT(Gfc2SphereBinarySerializer,"Gfc2SphereB",0)

int Gfc2SphereBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Sphere* pEnt = (Gfc2Sphere*)pEntity;
    int total_size = Gfc2SurfaceBinarySerializer::byteSize(pEnt);

    if (pEnt->hasRadius())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasCoords())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCoords());
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

void Gfc2SphereBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Sphere* pEnt = (Gfc2Sphere*)pEntity;
    Gfc2SurfaceBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasRadius())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(1, pEnt->getRadius(), output);
    }

    if (pEnt->hasCoords())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getCoords(), output);
    }

    if (pEnt->hasRangeU())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getRangeU(), output);
    }

    if (pEnt->hasRangeV())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getRangeV(), output);
    }

}

google::protobuf::uint8* Gfc2SphereBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Sphere* pEnt = (Gfc2Sphere*)pEntity;
    target = Gfc2SurfaceBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasRadius())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, pEnt->getRadius(), target);
    }

    if (pEnt->hasCoords())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getCoords(), target);
    }

    if (pEnt->hasRangeU())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getRangeU(), target);
    }

    if (pEnt->hasRangeV())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getRangeV(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2SphereBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Sphere* pEnt = (Gfc2Sphere*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SurfaceBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Sphere_Radius)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setRadius(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Sphere_Coords)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCoords(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Sphere_RangeU)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRangeU(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Sphere_RangeV)
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


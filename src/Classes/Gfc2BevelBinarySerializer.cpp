#include "StdAfx.h"
#include "Gfc2BevelBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Bevel.h"

OBJECTBUF_IMP_OBJECT(Gfc2BevelBinarySerializer,"Gfc2BevelB",0)

int Gfc2BevelBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Bevel* pEnt = (Gfc2Bevel*)pEntity;
    int total_size = Gfc2SurfaceBinarySerializer::byteSize(pEnt);

    if (pEnt->hasCoord())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCoord());
    }

    if (pEnt->hasHeight())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasRangeV())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRangeV());
    }

    if (pEnt->hasCurve())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCurve());
    }

    return total_size;
}

void Gfc2BevelBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Bevel* pEnt = (Gfc2Bevel*)pEntity;
    Gfc2SurfaceBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasCoord())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getCoord(), output);
    }

    if (pEnt->hasHeight())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(2, pEnt->getHeight(), output);
    }

    if (pEnt->hasRangeV())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getRangeV(), output);
    }

    if (pEnt->hasCurve())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getCurve(), output);
    }

}

google::protobuf::uint8* Gfc2BevelBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Bevel* pEnt = (Gfc2Bevel*)pEntity;
    target = Gfc2SurfaceBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasCoord())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getCoord(), target);
    }

    if (pEnt->hasHeight())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, pEnt->getHeight(), target);
    }

    if (pEnt->hasRangeV())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getRangeV(), target);
    }

    if (pEnt->hasCurve())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getCurve(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2BevelBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Bevel* pEnt = (Gfc2Bevel*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SurfaceBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Bevel_Coord)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCoord(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Bevel_Height)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setHeight(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Bevel_RangeV)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRangeV(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Bevel_Curve)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCurve(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


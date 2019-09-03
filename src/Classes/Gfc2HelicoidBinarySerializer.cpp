#include "StdAfx.h"
#include "Gfc2HelicoidBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Helicoid.h"

OBJECTBUF_IMP_OBJECT(Gfc2HelicoidBinarySerializer,"Gfc2HelicoidB",0)

int Gfc2HelicoidBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Helicoid* pEnt = (Gfc2Helicoid*)pEntity;
    int total_size = Gfc2SurfaceBinarySerializer::byteSize(pEnt);

    if (pEnt->hasCoord())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCoord());
    }

    if (pEnt->hasRadius())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasRangeV())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRangeV());
    }

    if (pEnt->hasClockSign())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getClockSign());
    }

    if (pEnt->hasHeightCoef())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasRadiusCoef())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasCurve())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCurve());
    }

    return total_size;
}

void Gfc2HelicoidBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Helicoid* pEnt = (Gfc2Helicoid*)pEntity;
    Gfc2SurfaceBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasCoord())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getCoord(), output);
    }

    if (pEnt->hasRadius())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(2, pEnt->getRadius(), output);
    }

    if (pEnt->hasRangeV())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getRangeV(), output);
    }

    if (pEnt->hasClockSign())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getClockSign(), output);
    }

    if (pEnt->hasHeightCoef())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(5, pEnt->getHeightCoef(), output);
    }

    if (pEnt->hasRadiusCoef())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(6, pEnt->getRadiusCoef(), output);
    }

    if (pEnt->hasCurve())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(7, pEnt->getCurve(), output);
    }

}

google::protobuf::uint8* Gfc2HelicoidBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Helicoid* pEnt = (Gfc2Helicoid*)pEntity;
    target = Gfc2SurfaceBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasCoord())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getCoord(), target);
    }

    if (pEnt->hasRadius())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, pEnt->getRadius(), target);
    }

    if (pEnt->hasRangeV())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getRangeV(), target);
    }

    if (pEnt->hasClockSign())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getClockSign(), target);
    }

    if (pEnt->hasHeightCoef())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(5, pEnt->getHeightCoef(), target);
    }

    if (pEnt->hasRadiusCoef())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(6, pEnt->getRadiusCoef(), target);
    }

    if (pEnt->hasCurve())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, pEnt->getCurve(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2HelicoidBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Helicoid* pEnt = (Gfc2Helicoid*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SurfaceBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Helicoid_Coord)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCoord(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Helicoid_Radius)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setRadius(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Helicoid_RangeV)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRangeV(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Helicoid_ClockSign)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setClockSign(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Helicoid_HeightCoef)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setHeightCoef(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Helicoid_RadiusCoef)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setRadiusCoef(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Helicoid_Curve)
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


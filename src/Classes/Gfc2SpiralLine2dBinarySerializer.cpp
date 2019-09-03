#include "StdAfx.h"
#include "Gfc2SpiralLine2dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2SpiralLine2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2SpiralLine2dBinarySerializer,"Gfc2SpiralLine2dB",0)

int Gfc2SpiralLine2dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SpiralLine2d* pEnt = (Gfc2SpiralLine2d*)pEntity;
    int total_size = Gfc2Curve2dBinarySerializer::byteSize(pEnt);

    if (pEnt->hasCoord())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCoord());
    }

    if (pEnt->hasRadius())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasRange())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRange());
    }

    if (pEnt->hasClockSign())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getClockSign());
    }

    if (pEnt->hasRadiusCoef())
    {
        total_size += 1 + 8;
    }

    return total_size;
}

void Gfc2SpiralLine2dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SpiralLine2d* pEnt = (Gfc2SpiralLine2d*)pEntity;
    Gfc2Curve2dBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasCoord())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getCoord(), output);
    }

    if (pEnt->hasRadius())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(2, pEnt->getRadius(), output);
    }

    if (pEnt->hasRange())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getRange(), output);
    }

    if (pEnt->hasClockSign())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getClockSign(), output);
    }

    if (pEnt->hasRadiusCoef())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(5, pEnt->getRadiusCoef(), output);
    }

}

google::protobuf::uint8* Gfc2SpiralLine2dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SpiralLine2d* pEnt = (Gfc2SpiralLine2d*)pEntity;
    target = Gfc2Curve2dBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasCoord())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getCoord(), target);
    }

    if (pEnt->hasRadius())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, pEnt->getRadius(), target);
    }

    if (pEnt->hasRange())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getRange(), target);
    }

    if (pEnt->hasClockSign())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getClockSign(), target);
    }

    if (pEnt->hasRadiusCoef())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(5, pEnt->getRadiusCoef(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2SpiralLine2dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SpiralLine2d* pEnt = (Gfc2SpiralLine2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve2dBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2SpiralLine2d_Coord)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCoord(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SpiralLine2d_Radius)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setRadius(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SpiralLine2d_Range)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRange(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SpiralLine2d_ClockSign)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setClockSign(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SpiralLine2d_RadiusCoef)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setRadiusCoef(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


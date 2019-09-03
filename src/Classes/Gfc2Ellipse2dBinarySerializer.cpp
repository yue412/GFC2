#include "StdAfx.h"
#include "Gfc2Ellipse2dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Ellipse2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2Ellipse2dBinarySerializer,"Gfc2Ellipse2dB",0)

int Gfc2Ellipse2dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Ellipse2d* pEnt = (Gfc2Ellipse2d*)pEntity;
    int total_size = Gfc2Curve2dBinarySerializer::byteSize(pEnt);

    if (pEnt->hasCenterPt())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCenterPt());
    }

    if (pEnt->hasMajorAxis())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getMajorAxis());
    }

    if (pEnt->hasdMajorRad())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasdMinorRad())
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

    return total_size;
}

void Gfc2Ellipse2dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Ellipse2d* pEnt = (Gfc2Ellipse2d*)pEntity;
    Gfc2Curve2dBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasCenterPt())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getCenterPt(), output);
    }

    if (pEnt->hasMajorAxis())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getMajorAxis(), output);
    }

    if (pEnt->hasdMajorRad())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(3, pEnt->getdMajorRad(), output);
    }

    if (pEnt->hasdMinorRad())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(4, pEnt->getdMinorRad(), output);
    }

    if (pEnt->hasRange())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(5, pEnt->getRange(), output);
    }

    if (pEnt->hasClockSign())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(6, pEnt->getClockSign(), output);
    }

}

google::protobuf::uint8* Gfc2Ellipse2dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Ellipse2d* pEnt = (Gfc2Ellipse2d*)pEntity;
    target = Gfc2Curve2dBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasCenterPt())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getCenterPt(), target);
    }

    if (pEnt->hasMajorAxis())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getMajorAxis(), target);
    }

    if (pEnt->hasdMajorRad())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, pEnt->getdMajorRad(), target);
    }

    if (pEnt->hasdMinorRad())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, pEnt->getdMinorRad(), target);
    }

    if (pEnt->hasRange())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, pEnt->getRange(), target);
    }

    if (pEnt->hasClockSign())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, pEnt->getClockSign(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2Ellipse2dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Ellipse2d* pEnt = (Gfc2Ellipse2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve2dBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Ellipse2d_CenterPt)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCenterPt(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Ellipse2d_MajorAxis)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setMajorAxis(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Ellipse2d_dMajorRad)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setdMajorRad(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Ellipse2d_dMinorRad)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setdMinorRad(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Ellipse2d_Range)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRange(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Ellipse2d_ClockSign)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setClockSign(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


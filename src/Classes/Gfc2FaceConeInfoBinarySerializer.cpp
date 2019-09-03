#include "StdAfx.h"
#include "Gfc2FaceConeInfoBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2FaceConeInfo.h"

OBJECTBUF_IMP_OBJECT(Gfc2FaceConeInfoBinarySerializer,"Gfc2FaceConeInfoB",0)

int Gfc2FaceConeInfoBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2FaceConeInfo* pEnt = (Gfc2FaceConeInfo*)pEntity;
    int total_size = Gfc2FaceInfoBinarySerializer::byteSize(pEnt);

    if (pEnt->hasHeight())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasChord())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasCenterPoint())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCenterPoint());
    }

    if (pEnt->hasCheckInnerChord())
    {
        total_size += 1 + 1;
    }

    return total_size;
}

void Gfc2FaceConeInfoBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2FaceConeInfo* pEnt = (Gfc2FaceConeInfo*)pEntity;
    Gfc2FaceInfoBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasHeight())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(1, pEnt->getHeight(), output);
    }

    if (pEnt->hasChord())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(2, pEnt->getChord(), output);
    }

    if (pEnt->hasCenterPoint())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getCenterPoint(), output);
    }

    if (pEnt->hasCheckInnerChord())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(4, pEnt->getCheckInnerChord(), output);
    }

}

google::protobuf::uint8* Gfc2FaceConeInfoBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2FaceConeInfo* pEnt = (Gfc2FaceConeInfo*)pEntity;
    target = Gfc2FaceInfoBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasHeight())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, pEnt->getHeight(), target);
    }

    if (pEnt->hasChord())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, pEnt->getChord(), target);
    }

    if (pEnt->hasCenterPoint())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getCenterPoint(), target);
    }

    if (pEnt->hasCheckInnerChord())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, pEnt->getCheckInnerChord(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2FaceConeInfoBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2FaceConeInfo* pEnt = (Gfc2FaceConeInfo*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2FaceInfoBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2FaceConeInfo_Height)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setHeight(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2FaceConeInfo_Chord)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setChord(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2FaceConeInfo_CenterPoint)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCenterPoint(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2FaceConeInfo_CheckInnerChord)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setCheckInnerChord(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


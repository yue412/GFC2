#include "StdAfx.h"
#include "Gfc2FaceSphereInfoBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2FaceSphereInfo.h"

OBJECTBUF_IMP_OBJECT(Gfc2FaceSphereInfoBinarySerializer,"Gfc2FaceSphereInfoB",0)

int Gfc2FaceSphereInfoBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2FaceSphereInfo* pEnt = (Gfc2FaceSphereInfo*)pEntity;
    int total_size = Gfc2FaceInfoBinarySerializer::byteSize(pEnt);

    if (pEnt->hasCenterPoint())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCenterPoint());
    }

    if (pEnt->hasHeight())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasChord())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasCheckInnerChord())
    {
        total_size += 1 + 1;
    }

    return total_size;
}

void Gfc2FaceSphereInfoBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2FaceSphereInfo* pEnt = (Gfc2FaceSphereInfo*)pEntity;
    Gfc2FaceInfoBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasCenterPoint())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getCenterPoint(), output);
    }

    if (pEnt->hasHeight())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(2, pEnt->getHeight(), output);
    }

    if (pEnt->hasChord())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(3, pEnt->getChord(), output);
    }

    if (pEnt->hasCheckInnerChord())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(4, pEnt->getCheckInnerChord(), output);
    }

}

google::protobuf::uint8* Gfc2FaceSphereInfoBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2FaceSphereInfo* pEnt = (Gfc2FaceSphereInfo*)pEntity;
    target = Gfc2FaceInfoBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasCenterPoint())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getCenterPoint(), target);
    }

    if (pEnt->hasHeight())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, pEnt->getHeight(), target);
    }

    if (pEnt->hasChord())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, pEnt->getChord(), target);
    }

    if (pEnt->hasCheckInnerChord())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, pEnt->getCheckInnerChord(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2FaceSphereInfoBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2FaceSphereInfo* pEnt = (Gfc2FaceSphereInfo*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2FaceInfoBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2FaceSphereInfo_CenterPoint)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCenterPoint(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2FaceSphereInfo_Height)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setHeight(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2FaceSphereInfo_Chord)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setChord(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2FaceSphereInfo_CheckInnerChord)
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


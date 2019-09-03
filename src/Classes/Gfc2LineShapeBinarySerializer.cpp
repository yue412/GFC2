#include "StdAfx.h"
#include "Gfc2LineShapeBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2LineShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2LineShapeBinarySerializer,"Gfc2LineShapeB",0)

int Gfc2LineShapeBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2LineShape* pEnt = (Gfc2LineShape*)pEntity;
    int total_size = Gfc2CustomLineShapeBinarySerializer::byteSize(pEnt);

    if (pEnt->hasTilt())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasStartPtHeight())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasEndPtHeight())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasArcInfo())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getArcInfo());
    }

    if (pEnt->hasIsSpiralTop())
    {
        total_size += 1 + 1;
    }

    if (pEnt->hasIsSpiralBtm())
    {
        total_size += 1 + 1;
    }

    return total_size;
}

void Gfc2LineShapeBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2LineShape* pEnt = (Gfc2LineShape*)pEntity;
    Gfc2CustomLineShapeBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasTilt())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(9, pEnt->getTilt(), output);
    }

    if (pEnt->hasStartPtHeight())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(10, pEnt->getStartPtHeight(), output);
    }

    if (pEnt->hasEndPtHeight())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(11, pEnt->getEndPtHeight(), output);
    }

    if (pEnt->hasArcInfo())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(12, pEnt->getArcInfo(), output);
    }

    if (pEnt->hasIsSpiralTop())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(13, pEnt->getIsSpiralTop(), output);
    }

    if (pEnt->hasIsSpiralBtm())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(14, pEnt->getIsSpiralBtm(), output);
    }

}

google::protobuf::uint8* Gfc2LineShapeBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2LineShape* pEnt = (Gfc2LineShape*)pEntity;
    target = Gfc2CustomLineShapeBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasTilt())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(9, pEnt->getTilt(), target);
    }

    if (pEnt->hasStartPtHeight())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(10, pEnt->getStartPtHeight(), target);
    }

    if (pEnt->hasEndPtHeight())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(11, pEnt->getEndPtHeight(), target);
    }

    if (pEnt->hasArcInfo())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(12, pEnt->getArcInfo(), target);
    }

    if (pEnt->hasIsSpiralTop())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(13, pEnt->getIsSpiralTop(), target);
    }

    if (pEnt->hasIsSpiralBtm())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(14, pEnt->getIsSpiralBtm(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2LineShapeBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2LineShape* pEnt = (Gfc2LineShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2CustomLineShapeBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2LineShape_Tilt)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setTilt(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2LineShape_StartPtHeight)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setStartPtHeight(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2LineShape_EndPtHeight)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setEndPtHeight(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2LineShape_ArcInfo)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setArcInfo(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2LineShape_IsSpiralTop)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setIsSpiralTop(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2LineShape_IsSpiralBtm)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setIsSpiralBtm(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


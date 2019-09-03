#include "StdAfx.h"
#include "Gfc2PointShape2dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2PointShape2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2PointShape2dBinarySerializer,"Gfc2PointShape2dB",0)

int Gfc2PointShape2dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PointShape2d* pEnt = (Gfc2PointShape2d*)pEntity;
    int total_size = Gfc2Shape2dBinarySerializer::byteSize(pEnt);

    if (pEnt->hasInsertPt())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getInsertPt());
    }

    if (pEnt->hasAngle())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasMirrorFlag())
    {
        total_size += 1 + 1;
    }

    return total_size;
}

void Gfc2PointShape2dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PointShape2d* pEnt = (Gfc2PointShape2d*)pEntity;
    Gfc2Shape2dBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasInsertPt())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getInsertPt(), output);
    }

    if (pEnt->hasAngle())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(5, pEnt->getAngle(), output);
    }

    if (pEnt->hasMirrorFlag())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(6, pEnt->getMirrorFlag(), output);
    }

}

google::protobuf::uint8* Gfc2PointShape2dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PointShape2d* pEnt = (Gfc2PointShape2d*)pEntity;
    target = Gfc2Shape2dBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasInsertPt())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getInsertPt(), target);
    }

    if (pEnt->hasAngle())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(5, pEnt->getAngle(), target);
    }

    if (pEnt->hasMirrorFlag())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(6, pEnt->getMirrorFlag(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2PointShape2dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PointShape2d* pEnt = (Gfc2PointShape2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Shape2dBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2PointShape2d_InsertPt)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setInsertPt(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PointShape2d_Angle)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setAngle(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PointShape2d_MirrorFlag)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setMirrorFlag(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


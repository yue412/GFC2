#include "StdAfx.h"
#include "Gfc2LineArcInfoBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2LineArcInfo.h"

OBJECTBUF_IMP_OBJECT(Gfc2LineArcInfoBinarySerializer,"Gfc2LineArcInfoB",0)

int Gfc2LineArcInfoBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2LineArcInfo* pEnt = (Gfc2LineArcInfo*)pEntity;
    int total_size = Gfc2BaseLineArcInfoBinarySerializer::byteSize(pEnt);

    if (pEnt->hasBasePoint())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getBasePoint());
    }

    if (pEnt->hasArchHeight())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasHalfChordLength())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasRadius())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasDefineByRadius())
    {
        total_size += 1 + 1;
    }

    return total_size;
}

void Gfc2LineArcInfoBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2LineArcInfo* pEnt = (Gfc2LineArcInfo*)pEntity;
    Gfc2BaseLineArcInfoBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasBasePoint())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getBasePoint(), output);
    }

    if (pEnt->hasArchHeight())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(2, pEnt->getArchHeight(), output);
    }

    if (pEnt->hasHalfChordLength())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(3, pEnt->getHalfChordLength(), output);
    }

    if (pEnt->hasRadius())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(4, pEnt->getRadius(), output);
    }

    if (pEnt->hasDefineByRadius())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(5, pEnt->getDefineByRadius(), output);
    }

}

google::protobuf::uint8* Gfc2LineArcInfoBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2LineArcInfo* pEnt = (Gfc2LineArcInfo*)pEntity;
    target = Gfc2BaseLineArcInfoBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasBasePoint())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getBasePoint(), target);
    }

    if (pEnt->hasArchHeight())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, pEnt->getArchHeight(), target);
    }

    if (pEnt->hasHalfChordLength())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, pEnt->getHalfChordLength(), target);
    }

    if (pEnt->hasRadius())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, pEnt->getRadius(), target);
    }

    if (pEnt->hasDefineByRadius())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(5, pEnt->getDefineByRadius(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2LineArcInfoBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2LineArcInfo* pEnt = (Gfc2LineArcInfo*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2BaseLineArcInfoBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2LineArcInfo_BasePoint)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setBasePoint(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2LineArcInfo_ArchHeight)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setArchHeight(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2LineArcInfo_HalfChordLength)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setHalfChordLength(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2LineArcInfo_Radius)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setRadius(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2LineArcInfo_DefineByRadius)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setDefineByRadius(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


#include "StdAfx.h"
#include "Gfc2IntervaldBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Intervald.h"

OBJECTBUF_IMP_OBJECT(Gfc2IntervaldBinarySerializer,"Gfc2IntervaldB",0)

int Gfc2IntervaldBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Intervald* pEnt = (Gfc2Intervald*)pEntity;
    int total_size = Gfc2GeometryBinarySerializer::byteSize(pEnt);

    if (pEnt->hasMin())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasMax())
    {
        total_size += 1 + 8;
    }

    return total_size;
}

void Gfc2IntervaldBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Intervald* pEnt = (Gfc2Intervald*)pEntity;
    Gfc2GeometryBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasMin())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(1, pEnt->getMin(), output);
    }

    if (pEnt->hasMax())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(2, pEnt->getMax(), output);
    }

}

google::protobuf::uint8* Gfc2IntervaldBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Intervald* pEnt = (Gfc2Intervald*)pEntity;
    target = Gfc2GeometryBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasMin())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, pEnt->getMin(), target);
    }

    if (pEnt->hasMax())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, pEnt->getMax(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2IntervaldBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Intervald* pEnt = (Gfc2Intervald*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2GeometryBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Intervald_Min)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setMin(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Intervald_Max)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setMax(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


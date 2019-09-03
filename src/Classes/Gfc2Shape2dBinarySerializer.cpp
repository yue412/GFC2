#include "StdAfx.h"
#include "Gfc2Shape2dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Shape2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2Shape2dBinarySerializer,"Gfc2Shape2dB",0)

int Gfc2Shape2dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Shape2d* pEnt = (Gfc2Shape2d*)pEntity;
    int total_size = Gfc2ParametricShapeBinarySerializer::byteSize(pEnt);

    if (pEnt->hasElev())
    {
        total_size += 1 + 8;
    }

    return total_size;
}

void Gfc2Shape2dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Shape2d* pEnt = (Gfc2Shape2d*)pEntity;
    Gfc2ParametricShapeBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasElev())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(3, pEnt->getElev(), output);
    }

}

google::protobuf::uint8* Gfc2Shape2dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Shape2d* pEnt = (Gfc2Shape2d*)pEntity;
    target = Gfc2ParametricShapeBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasElev())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, pEnt->getElev(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2Shape2dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Shape2d* pEnt = (Gfc2Shape2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2ParametricShapeBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Shape2d_Elev)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setElev(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


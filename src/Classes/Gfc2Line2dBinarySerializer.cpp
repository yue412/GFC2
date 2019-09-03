#include "StdAfx.h"
#include "Gfc2Line2dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Line2d.h"

OBJECTBUF_IMP_OBJECT(Gfc2Line2dBinarySerializer,"Gfc2Line2dB",0)

int Gfc2Line2dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Line2d* pEnt = (Gfc2Line2d*)pEntity;
    int total_size = Gfc2Curve2dBinarySerializer::byteSize(pEnt);

    if (pEnt->hasStartPt())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getStartPt());
    }

    if (pEnt->hasEndPt())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getEndPt());
    }

    return total_size;
}

void Gfc2Line2dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Line2d* pEnt = (Gfc2Line2d*)pEntity;
    Gfc2Curve2dBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasStartPt())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getStartPt(), output);
    }

    if (pEnt->hasEndPt())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getEndPt(), output);
    }

}

google::protobuf::uint8* Gfc2Line2dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Line2d* pEnt = (Gfc2Line2d*)pEntity;
    target = Gfc2Curve2dBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasStartPt())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getStartPt(), target);
    }

    if (pEnt->hasEndPt())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getEndPt(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2Line2dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Line2d* pEnt = (Gfc2Line2d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve2dBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Line2d_StartPt)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setStartPt(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Line2d_EndPt)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setEndPt(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


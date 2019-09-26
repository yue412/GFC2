#include "StdAfx.h"
#include "Gfc2TwoPointAssitAxisBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2TwoPointAssitAxis.h"

OBJECTBUF_IMP_OBJECT(Gfc2TwoPointAssitAxisBinarySerializer,"Gfc2TwoPointAssitAxisB",0)

int Gfc2TwoPointAssitAxisBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2TwoPointAssitAxis* pEnt = (Gfc2TwoPointAssitAxis*)pEntity;
    int total_size = Gfc2AssitAxisBinarySerializer::byteSize(pEnt);

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

void Gfc2TwoPointAssitAxisBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2TwoPointAssitAxis* pEnt = (Gfc2TwoPointAssitAxis*)pEntity;
    Gfc2AssitAxisBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasStartPt())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(9, pEnt->getStartPt(), output);
    }

    if (pEnt->hasEndPt())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(10, pEnt->getEndPt(), output);
    }

}

google::protobuf::uint8* Gfc2TwoPointAssitAxisBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2TwoPointAssitAxis* pEnt = (Gfc2TwoPointAssitAxis*)pEntity;
    target = Gfc2AssitAxisBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasStartPt())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, pEnt->getStartPt(), target);
    }

    if (pEnt->hasEndPt())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(10, pEnt->getEndPt(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2TwoPointAssitAxisBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2TwoPointAssitAxis* pEnt = (Gfc2TwoPointAssitAxis*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2AssitAxisBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2TwoPointAssitAxis_StartPt)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setStartPt(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2TwoPointAssitAxis_EndPt)
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


#include "StdAfx.h"
#include "Gfc2Box3dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Box3d.h"

OBJECTBUF_IMP_OBJECT(Gfc2Box3dBinarySerializer,"Gfc2Box3dB",0)

int Gfc2Box3dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Box3d* pEnt = (Gfc2Box3d*)pEntity;
    int total_size = Gfc2GeometryBinarySerializer::byteSize(pEnt);

    if (pEnt->hasMin())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getMin());
    }

    if (pEnt->hasMax())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getMax());
    }

    return total_size;
}

void Gfc2Box3dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Box3d* pEnt = (Gfc2Box3d*)pEntity;
    Gfc2GeometryBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasMin())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getMin(), output);
    }

    if (pEnt->hasMax())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getMax(), output);
    }

}

google::protobuf::uint8* Gfc2Box3dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Box3d* pEnt = (Gfc2Box3d*)pEntity;
    target = Gfc2GeometryBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasMin())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getMin(), target);
    }

    if (pEnt->hasMax())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getMax(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2Box3dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Box3d* pEnt = (Gfc2Box3d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2GeometryBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Box3d_Min)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setMin(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Box3d_Max)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
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


#include "StdAfx.h"
#include "Gfc2RuledSurfaceBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2RuledSurface.h"

OBJECTBUF_IMP_OBJECT(Gfc2RuledSurfaceBinarySerializer,"Gfc2RuledSurfaceB",0)

int Gfc2RuledSurfaceBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RuledSurface* pEnt = (Gfc2RuledSurface*)pEntity;
    int total_size = Gfc2SurfaceBinarySerializer::byteSize(pEnt);

    if (pEnt->hasApexIndex())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getApexIndex());
    }

    if (pEnt->hasRangeV())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRangeV());
    }

    if (pEnt->hasRangeU())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRangeU());
    }

    if (pEnt->hasDirectrix1())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDirectrix1());
    }

    if (pEnt->hasDirectrix2())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDirectrix2());
    }

    return total_size;
}

void Gfc2RuledSurfaceBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RuledSurface* pEnt = (Gfc2RuledSurface*)pEntity;
    Gfc2SurfaceBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasApexIndex())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getApexIndex(), output);
    }

    if (pEnt->hasRangeV())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getRangeV(), output);
    }

    if (pEnt->hasRangeU())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getRangeU(), output);
    }

    if (pEnt->hasDirectrix1())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getDirectrix1(), output);
    }

    if (pEnt->hasDirectrix2())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(5, pEnt->getDirectrix2(), output);
    }

}

google::protobuf::uint8* Gfc2RuledSurfaceBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RuledSurface* pEnt = (Gfc2RuledSurface*)pEntity;
    target = Gfc2SurfaceBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasApexIndex())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getApexIndex(), target);
    }

    if (pEnt->hasRangeV())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getRangeV(), target);
    }

    if (pEnt->hasRangeU())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getRangeU(), target);
    }

    if (pEnt->hasDirectrix1())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getDirectrix1(), target);
    }

    if (pEnt->hasDirectrix2())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, pEnt->getDirectrix2(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2RuledSurfaceBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2RuledSurface* pEnt = (Gfc2RuledSurface*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SurfaceBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2RuledSurface_ApexIndex)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setApexIndex(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2RuledSurface_RangeV)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRangeV(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2RuledSurface_RangeU)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setRangeU(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2RuledSurface_Directrix1)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDirectrix1(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2RuledSurface_Directrix2)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDirectrix2(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


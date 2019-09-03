#include "StdAfx.h"
#include "Gfc2ExtrudedBodyBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2ExtrudedBody.h"

OBJECTBUF_IMP_OBJECT(Gfc2ExtrudedBodyBinarySerializer,"Gfc2ExtrudedBodyB",0)

int Gfc2ExtrudedBodyBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2ExtrudedBody* pEnt = (Gfc2ExtrudedBody*)pEntity;
    int total_size = Gfc2BodyBinarySerializer::byteSize(pEnt);

    if (pEnt->hasCoordinate())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCoordinate());
    }

    if (pEnt->hasLength())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasSection())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getSection());
    }

    return total_size;
}

void Gfc2ExtrudedBodyBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2ExtrudedBody* pEnt = (Gfc2ExtrudedBody*)pEntity;
    Gfc2BodyBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasCoordinate())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getCoordinate(), output);
    }

    if (pEnt->hasLength())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(2, pEnt->getLength(), output);
    }

    if (pEnt->hasSection())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getSection(), output);
    }

}

google::protobuf::uint8* Gfc2ExtrudedBodyBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2ExtrudedBody* pEnt = (Gfc2ExtrudedBody*)pEntity;
    target = Gfc2BodyBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasCoordinate())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getCoordinate(), target);
    }

    if (pEnt->hasLength())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, pEnt->getLength(), target);
    }

    if (pEnt->hasSection())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getSection(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2ExtrudedBodyBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2ExtrudedBody* pEnt = (Gfc2ExtrudedBody*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2BodyBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2ExtrudedBody_Coordinate)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCoordinate(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2ExtrudedBody_Length)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setLength(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2ExtrudedBody_Section)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setSection(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


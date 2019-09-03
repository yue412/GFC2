#include "StdAfx.h"
#include "Gfc2SimpleVertexBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2SimpleVertex.h"

OBJECTBUF_IMP_OBJECT(Gfc2SimpleVertexBinarySerializer,"Gfc2SimpleVertexB",0)

int Gfc2SimpleVertexBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SimpleVertex* pEnt = (Gfc2SimpleVertex*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasPoint())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getPoint());
    }

    if (pEnt->hasRadius())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasArcType())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size((int)pEnt->getArcType());
    }

    return total_size;
}

void Gfc2SimpleVertexBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SimpleVertex* pEnt = (Gfc2SimpleVertex*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasPoint())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getPoint(), output);
    }

    if (pEnt->hasRadius())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(2, pEnt->getRadius(), output);
    }

    if (pEnt->hasArcType())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, (int)pEnt->getArcType(), output);
    }

}

google::protobuf::uint8* Gfc2SimpleVertexBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SimpleVertex* pEnt = (Gfc2SimpleVertex*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasPoint())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getPoint(), target);
    }

    if (pEnt->hasRadius())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, pEnt->getRadius(), target);
    }

    if (pEnt->hasArcType())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, (int)pEnt->getArcType(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2SimpleVertexBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SimpleVertex* pEnt = (Gfc2SimpleVertex*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2SimpleVertex_Point)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setPoint(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SimpleVertex_Radius)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setRadius(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SimpleVertex_ArcType)
    {
        Gfc2ArcType value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, (google::protobuf::int32*)&value)));
        pEnt->setArcType(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


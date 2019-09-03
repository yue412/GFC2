#include "StdAfx.h"
#include "Gfc2PolyhedralEdgeBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2PolyhedralEdge.h"

OBJECTBUF_IMP_OBJECT(Gfc2PolyhedralEdgeBinarySerializer,"Gfc2PolyhedralEdgeB",0)

int Gfc2PolyhedralEdgeBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PolyhedralEdge* pEnt = (Gfc2PolyhedralEdge*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasStartVertexIndex())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getStartVertexIndex());
    }

    if (pEnt->hasEndVertexIndex())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getEndVertexIndex());
    }

    return total_size;
}

void Gfc2PolyhedralEdgeBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PolyhedralEdge* pEnt = (Gfc2PolyhedralEdge*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasStartVertexIndex())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getStartVertexIndex(), output);
    }

    if (pEnt->hasEndVertexIndex())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getEndVertexIndex(), output);
    }

}

google::protobuf::uint8* Gfc2PolyhedralEdgeBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PolyhedralEdge* pEnt = (Gfc2PolyhedralEdge*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasStartVertexIndex())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getStartVertexIndex(), target);
    }

    if (pEnt->hasEndVertexIndex())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getEndVertexIndex(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2PolyhedralEdgeBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PolyhedralEdge* pEnt = (Gfc2PolyhedralEdge*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2PolyhedralEdge_StartVertexIndex)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setStartVertexIndex(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PolyhedralEdge_EndVertexIndex)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setEndVertexIndex(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


#include "StdAfx.h"
#include "Gfc2CoedgeBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Coedge.h"

OBJECTBUF_IMP_OBJECT(Gfc2CoedgeBinarySerializer,"Gfc2CoedgeB",0)

int Gfc2CoedgeBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Coedge* pEnt = (Gfc2Coedge*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasCurve())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCurve());
    }

    if (pEnt->hasEdgeIndex())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getEdgeIndex());
    }

    if (pEnt->hasEdgeSameDir())
    {
        total_size += 1 + 1;
    }

    return total_size;
}

void Gfc2CoedgeBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Coedge* pEnt = (Gfc2Coedge*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasCurve())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getCurve(), output);
    }

    if (pEnt->hasEdgeIndex())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getEdgeIndex(), output);
    }

    if (pEnt->hasEdgeSameDir())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(3, pEnt->getEdgeSameDir(), output);
    }

}

google::protobuf::uint8* Gfc2CoedgeBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Coedge* pEnt = (Gfc2Coedge*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasCurve())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getCurve(), target);
    }

    if (pEnt->hasEdgeIndex())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getEdgeIndex(), target);
    }

    if (pEnt->hasEdgeSameDir())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, pEnt->getEdgeSameDir(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2CoedgeBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Coedge* pEnt = (Gfc2Coedge*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Coedge_Curve)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCurve(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Coedge_EdgeIndex)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setEdgeIndex(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Coedge_EdgeSameDir)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setEdgeSameDir(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


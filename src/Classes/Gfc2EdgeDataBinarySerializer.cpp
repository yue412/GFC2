#include "StdAfx.h"
#include "Gfc2EdgeDataBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2EdgeData.h"

OBJECTBUF_IMP_OBJECT(Gfc2EdgeDataBinarySerializer,"Gfc2EdgeDataB",0)

int Gfc2EdgeDataBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2EdgeData* pEnt = (Gfc2EdgeData*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasEdgeIndex())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getEdgeIndex());
    }

    if (pEnt->hasLoopIndex())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLoopIndex());
    }

    if (pEnt->hasType())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getType());
    }

    if (pEnt->hasEdgeInfo())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getEdgeInfo());
    }

    if (pEnt->hasParam())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getParam());
    }

    if (pEnt->hasBaseType())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getBaseType());
    }

    if (pEnt->hasSlopePoly())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getSlopePoly());
    }

    return total_size;
}

void Gfc2EdgeDataBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2EdgeData* pEnt = (Gfc2EdgeData*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasEdgeIndex())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getEdgeIndex(), output);
    }

    if (pEnt->hasLoopIndex())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getLoopIndex(), output);
    }

    if (pEnt->hasType())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getType(), output);
    }

    if (pEnt->hasEdgeInfo())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getEdgeInfo(), output);
    }

    if (pEnt->hasParam())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(5, pEnt->getParam(), output);
    }

    if (pEnt->hasBaseType())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(6, pEnt->getBaseType(), output);
    }

    if (pEnt->hasSlopePoly())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(7, pEnt->getSlopePoly(), output);
    }

}

google::protobuf::uint8* Gfc2EdgeDataBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2EdgeData* pEnt = (Gfc2EdgeData*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasEdgeIndex())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getEdgeIndex(), target);
    }

    if (pEnt->hasLoopIndex())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getLoopIndex(), target);
    }

    if (pEnt->hasType())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getType(), target);
    }

    if (pEnt->hasEdgeInfo())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getEdgeInfo(), target);
    }

    if (pEnt->hasParam())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, pEnt->getParam(), target);
    }

    if (pEnt->hasBaseType())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, pEnt->getBaseType(), target);
    }

    if (pEnt->hasSlopePoly())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, pEnt->getSlopePoly(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2EdgeDataBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2EdgeData* pEnt = (Gfc2EdgeData*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2EdgeData_EdgeIndex)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setEdgeIndex(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2EdgeData_LoopIndex)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setLoopIndex(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2EdgeData_Type)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setType(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2EdgeData_EdgeInfo)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setEdgeInfo(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2EdgeData_Param)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setParam(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2EdgeData_BaseType)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setBaseType(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2EdgeData_SlopePoly)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setSlopePoly(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


#include "StdAfx.h"
#include "Gfc2EdgeBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Edge.h"

OBJECTBUF_IMP_OBJECT(Gfc2EdgeBinarySerializer,"Gfc2EdgeB",0)

int Gfc2EdgeBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Edge* pEnt = (Gfc2Edge*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasCurve())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCurve());
    }

    if (pEnt->hasFaceIndex1())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getFaceIndex1());
    }

    if (pEnt->hasFaceIndex2())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getFaceIndex2());
    }

    if (pEnt->hasLoopIndex1())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLoopIndex1());
    }

    if (pEnt->hasLoopIndex2())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLoopIndex2());
    }

    if (pEnt->hasCoedgeIndex1())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCoedgeIndex1());
    }

    if (pEnt->hasCoedgeIndex2())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCoedgeIndex2());
    }

    return total_size;
}

void Gfc2EdgeBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Edge* pEnt = (Gfc2Edge*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasCurve())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getCurve(), output);
    }

    if (pEnt->hasFaceIndex1())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getFaceIndex1(), output);
    }

    if (pEnt->hasFaceIndex2())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getFaceIndex2(), output);
    }

    if (pEnt->hasLoopIndex1())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getLoopIndex1(), output);
    }

    if (pEnt->hasLoopIndex2())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(5, pEnt->getLoopIndex2(), output);
    }

    if (pEnt->hasCoedgeIndex1())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(6, pEnt->getCoedgeIndex1(), output);
    }

    if (pEnt->hasCoedgeIndex2())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(7, pEnt->getCoedgeIndex2(), output);
    }

}

google::protobuf::uint8* Gfc2EdgeBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Edge* pEnt = (Gfc2Edge*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasCurve())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getCurve(), target);
    }

    if (pEnt->hasFaceIndex1())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getFaceIndex1(), target);
    }

    if (pEnt->hasFaceIndex2())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getFaceIndex2(), target);
    }

    if (pEnt->hasLoopIndex1())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getLoopIndex1(), target);
    }

    if (pEnt->hasLoopIndex2())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, pEnt->getLoopIndex2(), target);
    }

    if (pEnt->hasCoedgeIndex1())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, pEnt->getCoedgeIndex1(), target);
    }

    if (pEnt->hasCoedgeIndex2())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, pEnt->getCoedgeIndex2(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2EdgeBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Edge* pEnt = (Gfc2Edge*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Edge_Curve)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCurve(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Edge_FaceIndex1)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setFaceIndex1(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Edge_FaceIndex2)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setFaceIndex2(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Edge_LoopIndex1)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setLoopIndex1(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Edge_LoopIndex2)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setLoopIndex2(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Edge_CoedgeIndex1)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCoedgeIndex1(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Edge_CoedgeIndex2)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCoedgeIndex2(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


#include "StdAfx.h"
#include "Gfc2SteelDetailBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2SteelDetail.h"

OBJECTBUF_IMP_OBJECT(Gfc2SteelDetailBinarySerializer,"Gfc2SteelDetailB",0)

int Gfc2SteelDetailBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SteelDetail* pEnt = (Gfc2SteelDetail*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasEntityID())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getEntityID());
    }

    if (pEnt->hasName())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getName());
    }

    if (pEnt->hasDesc())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDesc());
    }

    if (pEnt->hasLevel())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLevel());
    }

    if (pEnt->hasDia())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDia());
    }

    if (pEnt->hasNum())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getNum());
    }

    if (pEnt->hasLength())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLength());
    }

    if (pEnt->hasSingleWeight())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasTotalWeight())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasTieinNum())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getTieinNum());
    }

    if (pEnt->hasTieinType())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getTieinType());
    }

    return total_size;
}

void Gfc2SteelDetailBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SteelDetail* pEnt = (Gfc2SteelDetail*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasEntityID())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getEntityID(), output);
    }

    if (pEnt->hasName())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getName(), output);
    }

    if (pEnt->hasDesc())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getDesc(), output);
    }

    if (pEnt->hasLevel())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getLevel(), output);
    }

    if (pEnt->hasDia())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(5, pEnt->getDia(), output);
    }

    if (pEnt->hasNum())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(6, pEnt->getNum(), output);
    }

    if (pEnt->hasLength())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(7, pEnt->getLength(), output);
    }

    if (pEnt->hasSingleWeight())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(8, pEnt->getSingleWeight(), output);
    }

    if (pEnt->hasTotalWeight())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(9, pEnt->getTotalWeight(), output);
    }

    if (pEnt->hasTieinNum())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(10, pEnt->getTieinNum(), output);
    }

    if (pEnt->hasTieinType())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(11, pEnt->getTieinType(), output);
    }

}

google::protobuf::uint8* Gfc2SteelDetailBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SteelDetail* pEnt = (Gfc2SteelDetail*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasEntityID())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getEntityID(), target);
    }

    if (pEnt->hasName())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getName(), target);
    }

    if (pEnt->hasDesc())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getDesc(), target);
    }

    if (pEnt->hasLevel())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getLevel(), target);
    }

    if (pEnt->hasDia())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, pEnt->getDia(), target);
    }

    if (pEnt->hasNum())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, pEnt->getNum(), target);
    }

    if (pEnt->hasLength())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, pEnt->getLength(), target);
    }

    if (pEnt->hasSingleWeight())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(8, pEnt->getSingleWeight(), target);
    }

    if (pEnt->hasTotalWeight())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(9, pEnt->getTotalWeight(), target);
    }

    if (pEnt->hasTieinNum())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(10, pEnt->getTieinNum(), target);
    }

    if (pEnt->hasTieinType())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(11, pEnt->getTieinType(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2SteelDetailBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SteelDetail* pEnt = (Gfc2SteelDetail*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2SteelDetail_EntityID)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setEntityID(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SteelDetail_Name)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setName(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SteelDetail_Desc)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDesc(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SteelDetail_Level)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setLevel(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SteelDetail_Dia)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDia(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SteelDetail_Num)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setNum(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SteelDetail_Length)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setLength(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SteelDetail_SingleWeight)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setSingleWeight(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SteelDetail_TotalWeight)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setTotalWeight(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SteelDetail_TieinNum)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setTieinNum(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SteelDetail_TieinType)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setTieinType(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


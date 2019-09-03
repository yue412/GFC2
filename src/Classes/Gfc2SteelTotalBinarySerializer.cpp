#include "StdAfx.h"
#include "Gfc2SteelTotalBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2SteelTotal.h"

OBJECTBUF_IMP_OBJECT(Gfc2SteelTotalBinarySerializer,"Gfc2SteelTotalB",0)

int Gfc2SteelTotalBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SteelTotal* pEnt = (Gfc2SteelTotal*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasCompType())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCompType());
    }

    if (pEnt->hasLevel())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLevel());
    }

    if (pEnt->hasDia())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getDia());
    }

    if (pEnt->hasWeight())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasUnit())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getUnit());
    }

    return total_size;
}

void Gfc2SteelTotalBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SteelTotal* pEnt = (Gfc2SteelTotal*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasCompType())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getCompType(), output);
    }

    if (pEnt->hasLevel())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getLevel(), output);
    }

    if (pEnt->hasDia())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getDia(), output);
    }

    if (pEnt->hasWeight())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(4, pEnt->getWeight(), output);
    }

    if (pEnt->hasUnit())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(5, pEnt->getUnit(), output);
    }

}

google::protobuf::uint8* Gfc2SteelTotalBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SteelTotal* pEnt = (Gfc2SteelTotal*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasCompType())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getCompType(), target);
    }

    if (pEnt->hasLevel())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getLevel(), target);
    }

    if (pEnt->hasDia())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getDia(), target);
    }

    if (pEnt->hasWeight())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, pEnt->getWeight(), target);
    }

    if (pEnt->hasUnit())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, pEnt->getUnit(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2SteelTotalBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SteelTotal* pEnt = (Gfc2SteelTotal*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2SteelTotal_CompType)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCompType(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SteelTotal_Level)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setLevel(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SteelTotal_Dia)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setDia(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SteelTotal_Weight)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setWeight(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SteelTotal_Unit)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setUnit(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


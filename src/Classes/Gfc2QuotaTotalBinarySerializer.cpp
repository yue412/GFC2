#include "StdAfx.h"
#include "Gfc2QuotaTotalBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2QuotaTotal.h"

OBJECTBUF_IMP_OBJECT(Gfc2QuotaTotalBinarySerializer,"Gfc2QuotaTotalB",0)

int Gfc2QuotaTotalBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2QuotaTotal* pEnt = (Gfc2QuotaTotal*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasCode())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCode());
    }

    if (pEnt->hasSubCode())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getSubCode());
    }

    if (pEnt->hasName())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getName());
    }

    if (pEnt->hasContent())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getContent());
    }

    if (pEnt->hasUnit())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getUnit());
    }

    if (pEnt->hasQuantity())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getQuantity());
    }

    if (pEnt->hasMemo())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getMemo());
    }

    return total_size;
}

void Gfc2QuotaTotalBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2QuotaTotal* pEnt = (Gfc2QuotaTotal*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasCode())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getCode(), output);
    }

    if (pEnt->hasSubCode())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getSubCode(), output);
    }

    if (pEnt->hasName())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getName(), output);
    }

    if (pEnt->hasContent())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getContent(), output);
    }

    if (pEnt->hasUnit())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(5, pEnt->getUnit(), output);
    }

    if (pEnt->hasQuantity())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(6, pEnt->getQuantity(), output);
    }

    if (pEnt->hasMemo())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(7, pEnt->getMemo(), output);
    }

}

google::protobuf::uint8* Gfc2QuotaTotalBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2QuotaTotal* pEnt = (Gfc2QuotaTotal*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasCode())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getCode(), target);
    }

    if (pEnt->hasSubCode())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getSubCode(), target);
    }

    if (pEnt->hasName())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getName(), target);
    }

    if (pEnt->hasContent())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getContent(), target);
    }

    if (pEnt->hasUnit())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, pEnt->getUnit(), target);
    }

    if (pEnt->hasQuantity())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, pEnt->getQuantity(), target);
    }

    if (pEnt->hasMemo())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, pEnt->getMemo(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2QuotaTotalBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2QuotaTotal* pEnt = (Gfc2QuotaTotal*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2QuotaTotal_Code)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCode(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2QuotaTotal_SubCode)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setSubCode(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2QuotaTotal_Name)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setName(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2QuotaTotal_Content)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setContent(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2QuotaTotal_Unit)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setUnit(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2QuotaTotal_Quantity)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setQuantity(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2QuotaTotal_Memo)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setMemo(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


#include "StdAfx.h"
#include "Gfc2BillTotalBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2BillTotal.h"

OBJECTBUF_IMP_OBJECT(Gfc2BillTotalBinarySerializer,"Gfc2BillTotalB",0)

int Gfc2BillTotalBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2BillTotal* pEnt = (Gfc2BillTotal*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasCode())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCode());
    }

    if (pEnt->hasName())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getName());
    }

    if (pEnt->hasAttr())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getAttr());
    }

    if (pEnt->hasQuantityType())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getQuantityType());
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

void Gfc2BillTotalBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2BillTotal* pEnt = (Gfc2BillTotal*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasCode())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getCode(), output);
    }

    if (pEnt->hasName())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getName(), output);
    }

    if (pEnt->hasAttr())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getAttr(), output);
    }

    if (pEnt->hasQuantityType())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getQuantityType(), output);
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

google::protobuf::uint8* Gfc2BillTotalBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2BillTotal* pEnt = (Gfc2BillTotal*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasCode())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getCode(), target);
    }

    if (pEnt->hasName())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getName(), target);
    }

    if (pEnt->hasAttr())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getAttr(), target);
    }

    if (pEnt->hasQuantityType())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getQuantityType(), target);
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

glodon::objectbuf::EnParseFieldState Gfc2BillTotalBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2BillTotal* pEnt = (Gfc2BillTotal*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2BillTotal_Code)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCode(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2BillTotal_Name)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setName(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2BillTotal_Attr)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setAttr(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2BillTotal_QuantityType)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setQuantityType(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2BillTotal_Unit)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setUnit(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2BillTotal_Quantity)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setQuantity(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2BillTotal_Memo)
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


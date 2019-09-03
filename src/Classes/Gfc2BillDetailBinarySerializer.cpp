#include "StdAfx.h"
#include "Gfc2BillDetailBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2BillDetail.h"

OBJECTBUF_IMP_OBJECT(Gfc2BillDetailBinarySerializer,"Gfc2BillDetailB",0)

int Gfc2BillDetailBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2BillDetail* pEnt = (Gfc2BillDetail*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasFloorNum())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getFloorNum());
    }

    if (pEnt->hasEntityID())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getEntityID());
    }

    if (pEnt->hasUnit())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getUnit());
    }

    if (pEnt->hasExpress())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getExpress());
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

void Gfc2BillDetailBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2BillDetail* pEnt = (Gfc2BillDetail*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasFloorNum())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getFloorNum(), output);
    }

    if (pEnt->hasEntityID())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getEntityID(), output);
    }

    if (pEnt->hasUnit())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getUnit(), output);
    }

    if (pEnt->hasExpress())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, pEnt->getExpress(), output);
    }

    if (pEnt->hasQuantity())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(5, pEnt->getQuantity(), output);
    }

    if (pEnt->hasMemo())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(6, pEnt->getMemo(), output);
    }

}

google::protobuf::uint8* Gfc2BillDetailBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2BillDetail* pEnt = (Gfc2BillDetail*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasFloorNum())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getFloorNum(), target);
    }

    if (pEnt->hasEntityID())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getEntityID(), target);
    }

    if (pEnt->hasUnit())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getUnit(), target);
    }

    if (pEnt->hasExpress())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, pEnt->getExpress(), target);
    }

    if (pEnt->hasQuantity())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, pEnt->getQuantity(), target);
    }

    if (pEnt->hasMemo())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, pEnt->getMemo(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2BillDetailBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2BillDetail* pEnt = (Gfc2BillDetail*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2BillDetail_FloorNum)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setFloorNum(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2BillDetail_EntityID)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setEntityID(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2BillDetail_Unit)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setUnit(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2BillDetail_Express)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setExpress(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2BillDetail_Quantity)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setQuantity(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2BillDetail_Memo)
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


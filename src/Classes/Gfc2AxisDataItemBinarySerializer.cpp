#include "StdAfx.h"
#include "Gfc2AxisDataItemBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2AxisDataItem.h"

OBJECTBUF_IMP_OBJECT(Gfc2AxisDataItemBinarySerializer,"Gfc2AxisDataItemB",0)

int Gfc2AxisDataItemBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2AxisDataItem* pEnt = (Gfc2AxisDataItem*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasAxisNo())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getAxisNo());
    }

    if (pEnt->hasDistance())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasLevel())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLevel());
    }

    if (pEnt->hasAxisNoPos())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size((int)pEnt->getAxisNoPos());
    }

    if (pEnt->getTrimPointsCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getTrimPointsCount());
    for (int i = 0; i < pEnt->getTrimPointsCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getTrimPoints(i));
    }

    return total_size;
}

void Gfc2AxisDataItemBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2AxisDataItem* pEnt = (Gfc2AxisDataItem*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasAxisNo())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getAxisNo(), output);
    }

    if (pEnt->hasDistance())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(2, pEnt->getDistance(), output);
    }

    if (pEnt->hasLevel())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getLevel(), output);
    }

    if (pEnt->hasAxisNoPos())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(4, (int)pEnt->getAxisNoPos(), output);
    }

    if (pEnt->getTrimPointsCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(5, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getTrimPointsCount(), output);
        for (int i = 0; i < pEnt->getTrimPointsCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getTrimPoints(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2AxisDataItemBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2AxisDataItem* pEnt = (Gfc2AxisDataItem*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasAxisNo())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getAxisNo(), target);
    }

    if (pEnt->hasDistance())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, pEnt->getDistance(), target);
    }

    if (pEnt->hasLevel())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getLevel(), target);
    }

    if (pEnt->hasAxisNoPos())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, (int)pEnt->getAxisNoPos(), target);
    }

    if (pEnt->getTrimPointsCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(5, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getTrimPointsCount(), target);
        for (int i = 0; i < pEnt->getTrimPointsCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getTrimPoints(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2AxisDataItemBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2AxisDataItem* pEnt = (Gfc2AxisDataItem*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2AxisDataItem_AxisNo)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setAxisNo(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AxisDataItem_Distance)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setDistance(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AxisDataItem_Level)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setLevel(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AxisDataItem_AxisNoPos)
    {
        Gfc2AxisNoPosEnum value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, (google::protobuf::int32*)&value)));
        pEnt->setAxisNoPos(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AxisDataItem_TrimPoints)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addTrimPoints(value);
        }
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


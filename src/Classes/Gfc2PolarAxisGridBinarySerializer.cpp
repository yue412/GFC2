#include "StdAfx.h"
#include "Gfc2PolarAxisGridBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2PolarAxisGrid.h"

OBJECTBUF_IMP_OBJECT(Gfc2PolarAxisGridBinarySerializer,"Gfc2PolarAxisGridB",0)

int Gfc2PolarAxisGridBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PolarAxisGrid* pEnt = (Gfc2PolarAxisGrid*)pEntity;
    int total_size = Gfc2AxisGridBinarySerializer::byteSize(pEnt);

    if (pEnt->hasInsertPt())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getInsertPt());
    }

    if (pEnt->hasStartRadius())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasClockwise())
    {
        total_size += 1 + 1;
    }

    if (pEnt->getXKJCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getXKJCount());
    for (int i = 0; i < pEnt->getXKJCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getXKJ(i));
    }

    if (pEnt->getZJSCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getZJSCount());
    for (int i = 0; i < pEnt->getZJSCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getZJS(i));
    }

    return total_size;
}

void Gfc2PolarAxisGridBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PolarAxisGrid* pEnt = (Gfc2PolarAxisGrid*)pEntity;
    Gfc2AxisGridBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasInsertPt())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(6, pEnt->getInsertPt(), output);
    }

    if (pEnt->hasStartRadius())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(7, pEnt->getStartRadius(), output);
    }

    if (pEnt->hasClockwise())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(8, pEnt->getClockwise(), output);
    }

    if (pEnt->getXKJCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(9, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getXKJCount(), output);
        for (int i = 0; i < pEnt->getXKJCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getXKJ(i), output);
        }
    }

    if (pEnt->getZJSCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(10, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getZJSCount(), output);
        for (int i = 0; i < pEnt->getZJSCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getZJS(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2PolarAxisGridBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PolarAxisGrid* pEnt = (Gfc2PolarAxisGrid*)pEntity;
    target = Gfc2AxisGridBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasInsertPt())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, pEnt->getInsertPt(), target);
    }

    if (pEnt->hasStartRadius())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(7, pEnt->getStartRadius(), target);
    }

    if (pEnt->hasClockwise())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(8, pEnt->getClockwise(), target);
    }

    if (pEnt->getXKJCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(9, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getXKJCount(), target);
        for (int i = 0; i < pEnt->getXKJCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getXKJ(i), target);
        }
    }

    if (pEnt->getZJSCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(10, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getZJSCount(), target);
        for (int i = 0; i < pEnt->getZJSCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getZJS(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2PolarAxisGridBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PolarAxisGrid* pEnt = (Gfc2PolarAxisGrid*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2AxisGridBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2PolarAxisGrid_InsertPt)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setInsertPt(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PolarAxisGrid_StartRadius)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setStartRadius(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PolarAxisGrid_Clockwise)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setClockwise(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PolarAxisGrid_XKJ)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addXKJ(value);
        }
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2PolarAxisGrid_ZJS)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addZJS(value);
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


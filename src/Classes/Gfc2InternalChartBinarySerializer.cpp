#include "StdAfx.h"
#include "Gfc2InternalChartBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2InternalChart.h"

OBJECTBUF_IMP_OBJECT(Gfc2InternalChartBinarySerializer,"Gfc2InternalChartB",0)

int Gfc2InternalChartBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2InternalChart* pEnt = (Gfc2InternalChart*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasTra1())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasTra2())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasTra3())
    {
        total_size += 1 + 8;
    }

    if (pEnt->getIPSCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getIPSCount());
    for (int i = 0; i < pEnt->getIPSCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getIPS(i));
    }

    return total_size;
}

void Gfc2InternalChartBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2InternalChart* pEnt = (Gfc2InternalChart*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasTra1())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(1, pEnt->getTra1(), output);
    }

    if (pEnt->hasTra2())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(2, pEnt->getTra2(), output);
    }

    if (pEnt->hasTra3())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(3, pEnt->getTra3(), output);
    }

    if (pEnt->getIPSCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(4, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getIPSCount(), output);
        for (int i = 0; i < pEnt->getIPSCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getIPS(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2InternalChartBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2InternalChart* pEnt = (Gfc2InternalChart*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasTra1())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, pEnt->getTra1(), target);
    }

    if (pEnt->hasTra2())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, pEnt->getTra2(), target);
    }

    if (pEnt->hasTra3())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, pEnt->getTra3(), target);
    }

    if (pEnt->getIPSCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(4, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getIPSCount(), target);
        for (int i = 0; i < pEnt->getIPSCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getIPS(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2InternalChartBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2InternalChart* pEnt = (Gfc2InternalChart*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2InternalChart_Tra1)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setTra1(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2InternalChart_Tra2)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setTra2(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2InternalChart_Tra3)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setTra3(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2InternalChart_IPS)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addIPS(value);
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


#include "StdAfx.h"
#include "Gfc2AssitAxisBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2AssitAxis.h"

OBJECTBUF_IMP_OBJECT(Gfc2AssitAxisBinarySerializer,"Gfc2AssitAxisB",0)

int Gfc2AssitAxisBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2AssitAxis* pEnt = (Gfc2AssitAxis*)pEntity;
    int total_size = Gfc2EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasAxisNo())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getAxisNo());
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

void Gfc2AssitAxisBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2AssitAxis* pEnt = (Gfc2AssitAxis*)pEntity;
    Gfc2EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasAxisNo())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(6, pEnt->getAxisNo(), output);
    }

    if (pEnt->hasAxisNoPos())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(7, (int)pEnt->getAxisNoPos(), output);
    }

    if (pEnt->getTrimPointsCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(8, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getTrimPointsCount(), output);
        for (int i = 0; i < pEnt->getTrimPointsCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getTrimPoints(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2AssitAxisBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2AssitAxis* pEnt = (Gfc2AssitAxis*)pEntity;
    target = Gfc2EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasAxisNo())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, pEnt->getAxisNo(), target);
    }

    if (pEnt->hasAxisNoPos())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, (int)pEnt->getAxisNoPos(), target);
    }

    if (pEnt->getTrimPointsCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(8, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getTrimPointsCount(), target);
        for (int i = 0; i < pEnt->getTrimPointsCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getTrimPoints(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2AssitAxisBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2AssitAxis* pEnt = (Gfc2AssitAxis*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2AssitAxis_AxisNo)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setAxisNo(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AssitAxis_AxisNoPos)
    {
        Gfc2AxisNoPosEnum value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, (google::protobuf::int32*)&value)));
        pEnt->setAxisNoPos(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2AssitAxis_TrimPoints)
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


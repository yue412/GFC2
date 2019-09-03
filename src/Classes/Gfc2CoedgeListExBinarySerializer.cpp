#include "StdAfx.h"
#include "Gfc2CoedgeListExBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2CoedgeListEx.h"

OBJECTBUF_IMP_OBJECT(Gfc2CoedgeListExBinarySerializer,"Gfc2CoedgeListExB",0)

int Gfc2CoedgeListExBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CoedgeListEx* pEnt = (Gfc2CoedgeListEx*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->getCoedgeExsCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCoedgeExsCount());
    for (int i = 0; i < pEnt->getCoedgeExsCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCoedgeExs(i));
    }

    return total_size;
}

void Gfc2CoedgeListExBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CoedgeListEx* pEnt = (Gfc2CoedgeListEx*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->getCoedgeExsCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(1, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getCoedgeExsCount(), output);
        for (int i = 0; i < pEnt->getCoedgeExsCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getCoedgeExs(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2CoedgeListExBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CoedgeListEx* pEnt = (Gfc2CoedgeListEx*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->getCoedgeExsCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(1, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getCoedgeExsCount(), target);
        for (int i = 0; i < pEnt->getCoedgeExsCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getCoedgeExs(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2CoedgeListExBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CoedgeListEx* pEnt = (Gfc2CoedgeListEx*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2CoedgeListEx_CoedgeExs)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addCoedgeExs(value);
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


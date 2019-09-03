#include "StdAfx.h"
#include "Gfc2CommonPolygonExBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2CommonPolygonEx.h"

OBJECTBUF_IMP_OBJECT(Gfc2CommonPolygonExBinarySerializer,"Gfc2CommonPolygonExB",0)

int Gfc2CommonPolygonExBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CommonPolygonEx* pEnt = (Gfc2CommonPolygonEx*)pEntity;
    int total_size = Gfc2PolygonBinarySerializer::byteSize(pEnt);

    if (pEnt->getLoopExsCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLoopExsCount());
    for (int i = 0; i < pEnt->getLoopExsCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLoopExs(i));
    }

    return total_size;
}

void Gfc2CommonPolygonExBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CommonPolygonEx* pEnt = (Gfc2CommonPolygonEx*)pEntity;
    Gfc2PolygonBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->getLoopExsCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(1, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getLoopExsCount(), output);
        for (int i = 0; i < pEnt->getLoopExsCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getLoopExs(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2CommonPolygonExBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2CommonPolygonEx* pEnt = (Gfc2CommonPolygonEx*)pEntity;
    target = Gfc2PolygonBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->getLoopExsCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(1, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getLoopExsCount(), target);
        for (int i = 0; i < pEnt->getLoopExsCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getLoopExs(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2CommonPolygonExBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2CommonPolygonEx* pEnt = (Gfc2CommonPolygonEx*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2PolygonBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2CommonPolygonEx_LoopExs)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addLoopExs(value);
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


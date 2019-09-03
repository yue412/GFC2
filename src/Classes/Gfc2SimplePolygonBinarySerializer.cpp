#include "StdAfx.h"
#include "Gfc2SimplePolygonBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2SimplePolygon.h"

OBJECTBUF_IMP_OBJECT(Gfc2SimplePolygonBinarySerializer,"Gfc2SimplePolygonB",0)

int Gfc2SimplePolygonBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SimplePolygon* pEnt = (Gfc2SimplePolygon*)pEntity;
    int total_size = Gfc2PolygonBinarySerializer::byteSize(pEnt);

    if (pEnt->getLoopsCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLoopsCount());
    for (int i = 0; i < pEnt->getLoopsCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLoops(i));
    }

    return total_size;
}

void Gfc2SimplePolygonBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SimplePolygon* pEnt = (Gfc2SimplePolygon*)pEntity;
    Gfc2PolygonBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->getLoopsCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(1, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getLoopsCount(), output);
        for (int i = 0; i < pEnt->getLoopsCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getLoops(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2SimplePolygonBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SimplePolygon* pEnt = (Gfc2SimplePolygon*)pEntity;
    target = Gfc2PolygonBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->getLoopsCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(1, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getLoopsCount(), target);
        for (int i = 0; i < pEnt->getLoopsCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getLoops(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2SimplePolygonBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SimplePolygon* pEnt = (Gfc2SimplePolygon*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2PolygonBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2SimplePolygon_Loops)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addLoops(value);
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


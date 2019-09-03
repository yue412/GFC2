#include "StdAfx.h"
#include "Gfc2BrepBodyBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2BrepBody.h"

OBJECTBUF_IMP_OBJECT(Gfc2BrepBodyBinarySerializer,"Gfc2BrepBodyB",0)

int Gfc2BrepBodyBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2BrepBody* pEnt = (Gfc2BrepBody*)pEntity;
    int total_size = Gfc2BodyBinarySerializer::byteSize(pEnt);

    if (pEnt->getFacesCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getFacesCount());
    for (int i = 0; i < pEnt->getFacesCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getFaces(i));
    }

    if (pEnt->getEdgesCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getEdgesCount());
    for (int i = 0; i < pEnt->getEdgesCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getEdges(i));
    }

    return total_size;
}

void Gfc2BrepBodyBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2BrepBody* pEnt = (Gfc2BrepBody*)pEntity;
    Gfc2BodyBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->getFacesCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(1, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getFacesCount(), output);
        for (int i = 0; i < pEnt->getFacesCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getFaces(i), output);
        }
    }

    if (pEnt->getEdgesCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(2, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getEdgesCount(), output);
        for (int i = 0; i < pEnt->getEdgesCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getEdges(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2BrepBodyBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2BrepBody* pEnt = (Gfc2BrepBody*)pEntity;
    target = Gfc2BodyBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->getFacesCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(1, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getFacesCount(), target);
        for (int i = 0; i < pEnt->getFacesCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getFaces(i), target);
        }
    }

    if (pEnt->getEdgesCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(2, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getEdgesCount(), target);
        for (int i = 0; i < pEnt->getEdgesCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getEdges(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2BrepBodyBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2BrepBody* pEnt = (Gfc2BrepBody*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2BodyBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2BrepBody_Faces)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addFaces(value);
        }
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2BrepBody_Edges)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addEdges(value);
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


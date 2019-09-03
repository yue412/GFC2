#include "StdAfx.h"
#include "Gfc2RepresentationBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Representation.h"

OBJECTBUF_IMP_OBJECT(Gfc2RepresentationBinarySerializer,"Gfc2RepresentationB",0)

int Gfc2RepresentationBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Representation* pEnt = (Gfc2Representation*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasIdentifier())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getIdentifier());
    }

    if (pEnt->getitemsCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getitemsCount());
    for (int i = 0; i < pEnt->getitemsCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getitems(i));
    }

    return total_size;
}

void Gfc2RepresentationBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Representation* pEnt = (Gfc2Representation*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasIdentifier())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getIdentifier(), output);
    }

    if (pEnt->getitemsCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(2, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getitemsCount(), output);
        for (int i = 0; i < pEnt->getitemsCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getitems(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2RepresentationBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Representation* pEnt = (Gfc2Representation*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasIdentifier())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getIdentifier(), target);
    }

    if (pEnt->getitemsCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(2, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getitemsCount(), target);
        for (int i = 0; i < pEnt->getitemsCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getitems(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2RepresentationBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Representation* pEnt = (Gfc2Representation*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Representation_Identifier)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setIdentifier(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Representation_items)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->additems(value);
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


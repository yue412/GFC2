#include "StdAfx.h"
#include "Gfc2EntityBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Entity.h"

OBJECTBUF_IMP_OBJECT(Gfc2EntityBinarySerializer,"Gfc2EntityB",0)

int Gfc2EntityBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Entity* pEnt = (Gfc2Entity*)pEntity;
    int total_size = Gfc2ObjectBinarySerializer::byteSize(pEnt);

    if (pEnt->hasType())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getType());
    }

    if (pEnt->getRepresentationsCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRepresentationsCount());
    for (int i = 0; i < pEnt->getRepresentationsCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getRepresentations(i));
    }

    if (pEnt->getShapesCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getShapesCount());
    for (int i = 0; i < pEnt->getShapesCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getShapes(i));
    }

    return total_size;
}

void Gfc2EntityBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Entity* pEnt = (Gfc2Entity*)pEntity;
    Gfc2ObjectBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasType())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getType(), output);
    }

    if (pEnt->getRepresentationsCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(4, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getRepresentationsCount(), output);
        for (int i = 0; i < pEnt->getRepresentationsCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getRepresentations(i), output);
        }
    }

    if (pEnt->getShapesCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(5, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getShapesCount(), output);
        for (int i = 0; i < pEnt->getShapesCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getShapes(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2EntityBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Entity* pEnt = (Gfc2Entity*)pEntity;
    target = Gfc2ObjectBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasType())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getType(), target);
    }

    if (pEnt->getRepresentationsCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(4, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getRepresentationsCount(), target);
        for (int i = 0; i < pEnt->getRepresentationsCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getRepresentations(i), target);
        }
    }

    if (pEnt->getShapesCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(5, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getShapesCount(), target);
        for (int i = 0; i < pEnt->getShapesCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getShapes(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2EntityBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Entity* pEnt = (Gfc2Entity*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2ObjectBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Entity_Type)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setType(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Entity_Representations)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addRepresentations(value);
        }
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Entity_Shapes)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addShapes(value);
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


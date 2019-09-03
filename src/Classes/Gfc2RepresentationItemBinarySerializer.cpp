#include "StdAfx.h"
#include "Gfc2RepresentationItemBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2RepresentationItem.h"

OBJECTBUF_IMP_OBJECT(Gfc2RepresentationItemBinarySerializer,"Gfc2RepresentationItemB",0)

int Gfc2RepresentationItemBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RepresentationItem* pEnt = (Gfc2RepresentationItem*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->hasPrimitiveType())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size((int)pEnt->getPrimitiveType());
    }

    if (pEnt->hasGeometryDataType())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size((int)pEnt->getGeometryDataType());
    }

    if (pEnt->getVertexesCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getVertexesCount());
    for (int i = 0; i < pEnt->getVertexesCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getVertexes(i));
    }

    if (pEnt->getNormalsCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getNormalsCount());
    for (int i = 0; i < pEnt->getNormalsCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getNormals(i));
    }

    if (pEnt->getIndexesCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getIndexesCount());
    for (int i = 0; i < pEnt->getIndexesCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getIndexes(i));
    }

    if (pEnt->hasStateSet())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getStateSet());
    }

    return total_size;
}

void Gfc2RepresentationItemBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RepresentationItem* pEnt = (Gfc2RepresentationItem*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasPrimitiveType())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, (int)pEnt->getPrimitiveType(), output);
    }

    if (pEnt->hasGeometryDataType())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, (int)pEnt->getGeometryDataType(), output);
    }

    if (pEnt->getVertexesCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(3, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getVertexesCount(), output);
        for (int i = 0; i < pEnt->getVertexesCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getVertexes(i), output);
        }
    }

    if (pEnt->getNormalsCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(4, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getNormalsCount(), output);
        for (int i = 0; i < pEnt->getNormalsCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getNormals(i), output);
        }
    }

    if (pEnt->getIndexesCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(5, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getIndexesCount(), output);
        for (int i = 0; i < pEnt->getIndexesCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getIndexes(i), output);
        }
    }

    if (pEnt->hasStateSet())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(6, pEnt->getStateSet(), output);
    }

}

google::protobuf::uint8* Gfc2RepresentationItemBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2RepresentationItem* pEnt = (Gfc2RepresentationItem*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasPrimitiveType())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, (int)pEnt->getPrimitiveType(), target);
    }

    if (pEnt->hasGeometryDataType())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, (int)pEnt->getGeometryDataType(), target);
    }

    if (pEnt->getVertexesCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(3, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getVertexesCount(), target);
        for (int i = 0; i < pEnt->getVertexesCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getVertexes(i), target);
        }
    }

    if (pEnt->getNormalsCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(4, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getNormalsCount(), target);
        for (int i = 0; i < pEnt->getNormalsCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getNormals(i), target);
        }
    }

    if (pEnt->getIndexesCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(5, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getIndexesCount(), target);
        for (int i = 0; i < pEnt->getIndexesCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getIndexes(i), target);
        }
    }

    if (pEnt->hasStateSet())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, pEnt->getStateSet(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2RepresentationItemBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2RepresentationItem* pEnt = (Gfc2RepresentationItem*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2RepresentationItem_PrimitiveType)
    {
        Gfc2PrimitiveType value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, (google::protobuf::int32*)&value)));
        pEnt->setPrimitiveType(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2RepresentationItem_GeometryDataType)
    {
        Gfc2GeometryDataType value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, (google::protobuf::int32*)&value)));
        pEnt->setGeometryDataType(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2RepresentationItem_Vertexes)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addVertexes(value);
        }
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2RepresentationItem_Normals)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addNormals(value);
        }
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2RepresentationItem_Indexes)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            Gfc2Integer value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addIndexes(value);
        }
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2RepresentationItem_StateSet)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setStateSet(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


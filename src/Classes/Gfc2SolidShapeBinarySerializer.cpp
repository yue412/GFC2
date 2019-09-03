#include "StdAfx.h"
#include "Gfc2SolidShapeBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2SolidShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2SolidShapeBinarySerializer,"Gfc2SolidShapeB",0)

int Gfc2SolidShapeBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SolidShape* pEnt = (Gfc2SolidShape*)pEntity;
    int total_size = Gfc2Shape3dBinarySerializer::byteSize(pEnt);

    if (pEnt->hasBody())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getBody());
    }

    if (pEnt->getEdgeDatasCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getEdgeDatasCount());
    for (int i = 0; i < pEnt->getEdgeDatasCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getEdgeDatas(i));
    }

    return total_size;
}

void Gfc2SolidShapeBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SolidShape* pEnt = (Gfc2SolidShape*)pEntity;
    Gfc2Shape3dBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasBody())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getBody(), output);
    }

    if (pEnt->getEdgeDatasCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(4, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getEdgeDatasCount(), output);
        for (int i = 0; i < pEnt->getEdgeDatasCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getEdgeDatas(i), output);
        }
    }

}

google::protobuf::uint8* Gfc2SolidShapeBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2SolidShape* pEnt = (Gfc2SolidShape*)pEntity;
    target = Gfc2Shape3dBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasBody())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getBody(), target);
    }

    if (pEnt->getEdgeDatasCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(4, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getEdgeDatasCount(), target);
        for (int i = 0; i < pEnt->getEdgeDatasCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getEdgeDatas(i), target);
        }
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2SolidShapeBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2SolidShape* pEnt = (Gfc2SolidShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Shape3dBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2SolidShape_Body)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setBody(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2SolidShape_EdgeDatas)
    {
        int nSize = 0;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));
        for(int i = 0; i < nSize; ++i)
        {
            glodon::objectbuf::EntityRef value;
            DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
            pEnt->addEdgeDatas(value);
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


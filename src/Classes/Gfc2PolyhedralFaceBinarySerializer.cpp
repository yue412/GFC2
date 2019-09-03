#include "StdAfx.h"
#include "Gfc2PolyhedralFaceBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2PolyhedralFace.h"

OBJECTBUF_IMP_OBJECT(Gfc2PolyhedralFaceBinarySerializer,"Gfc2PolyhedralFaceB",0)

int Gfc2PolyhedralFaceBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PolyhedralFace* pEnt = (Gfc2PolyhedralFace*)pEntity;
    int total_size = glodon::objectbuf::EntityBinarySerializer::byteSize(pEnt);

    if (pEnt->getLoopsCount() > 0)
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLoopsCount());
    for (int i = 0; i < pEnt->getLoopsCount(); i++)
    {
        total_size += ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getLoops(i));
    }

    if (pEnt->hasPlane())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getPlane());
    }

    return total_size;
}

void Gfc2PolyhedralFaceBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PolyhedralFace* pEnt = (Gfc2PolyhedralFace*)pEntity;
    glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->getLoopsCount() > 0)
    {
        ::google::protobuf::internal::WireFormatLite::WriteTag(1, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getLoopsCount(), output);
        for (int i = 0; i < pEnt->getLoopsCount(); i++)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->getLoops(i), output);
        }
    }

    if (pEnt->hasPlane())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getPlane(), output);
    }

}

google::protobuf::uint8* Gfc2PolyhedralFaceBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2PolyhedralFace* pEnt = (Gfc2PolyhedralFace*)pEntity;
    target = glodon::objectbuf::EntityBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->getLoopsCount() > 0)
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(1, google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, target);
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getLoopsCount(), target);
        for (int i = 0; i < pEnt->getLoopsCount(); i++)
        {
            target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->getLoops(i), target);
        }
    }

    if (pEnt->hasPlane())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getPlane(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2PolyhedralFaceBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2PolyhedralFace* pEnt = (Gfc2PolyhedralFace*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = glodon::objectbuf::EntityBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2PolyhedralFace_Loops)
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

    if (nFieldNum == _FieldCache->_Gfc2PolyhedralFace_Plane)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setPlane(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


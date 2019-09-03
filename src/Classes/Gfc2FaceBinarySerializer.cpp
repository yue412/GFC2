#include "StdAfx.h"
#include "Gfc2FaceBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2Face.h"

OBJECTBUF_IMP_OBJECT(Gfc2FaceBinarySerializer,"Gfc2FaceB",0)

int Gfc2FaceBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Face* pEnt = (Gfc2Face*)pEntity;
    int total_size = Gfc2CommonPolygonExBinarySerializer::byteSize(pEnt);

    if (pEnt->hasSurface())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getSurface());
    }

    if (pEnt->hasBox())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getBox());
    }

    if (pEnt->hasSameDir())
    {
        total_size += 1 + 1;
    }

    if (pEnt->hasIndex())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getIndex());
    }

    return total_size;
}

void Gfc2FaceBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Face* pEnt = (Gfc2Face*)pEntity;
    Gfc2CommonPolygonExBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasSurface())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getSurface(), output);
    }

    if (pEnt->hasBox())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, pEnt->getBox(), output);
    }

    if (pEnt->hasSameDir())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(4, pEnt->getSameDir(), output);
    }

    if (pEnt->hasIndex())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(5, pEnt->getIndex(), output);
    }

}

google::protobuf::uint8* Gfc2FaceBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2Face* pEnt = (Gfc2Face*)pEntity;
    target = Gfc2CommonPolygonExBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasSurface())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getSurface(), target);
    }

    if (pEnt->hasBox())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, pEnt->getBox(), target);
    }

    if (pEnt->hasSameDir())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, pEnt->getSameDir(), target);
    }

    if (pEnt->hasIndex())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, pEnt->getIndex(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2FaceBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2Face* pEnt = (Gfc2Face*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2CommonPolygonExBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2Face_Surface)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setSurface(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Face_Box)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setBox(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Face_SameDir)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setSameDir(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2Face_Index)
    {
        Gfc2Integer value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setIndex(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


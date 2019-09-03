#include "StdAfx.h"
#include "Gfc2FaceShapeBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2FaceShape.h"

OBJECTBUF_IMP_OBJECT(Gfc2FaceShapeBinarySerializer,"Gfc2FaceShapeB",0)

int Gfc2FaceShapeBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2FaceShape* pEnt = (Gfc2FaceShape*)pEntity;
    int total_size = Gfc2SolidShapeBinarySerializer::byteSize(pEnt);

    if (pEnt->hasThickness())
    {
        total_size += 1 + 8;
    }

    if (pEnt->hasPoly())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getPoly());
    }

    if (pEnt->hasMirrorFlag())
    {
        total_size += 1 + 1;
    }

    if (pEnt->hasFaceInfo())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getFaceInfo());
    }

    return total_size;
}

void Gfc2FaceShapeBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2FaceShape* pEnt = (Gfc2FaceShape*)pEntity;
    Gfc2SolidShapeBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasThickness())
    {
        ::google::protobuf::internal::WireFormatLite::WriteDouble(5, pEnt->getThickness(), output);
    }

    if (pEnt->hasPoly())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(6, pEnt->getPoly(), output);
    }

    if (pEnt->hasMirrorFlag())
    {
        ::google::protobuf::internal::WireFormatLite::WriteBool(7, pEnt->getMirrorFlag(), output);
    }

    if (pEnt->hasFaceInfo())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(8, pEnt->getFaceInfo(), output);
    }

}

google::protobuf::uint8* Gfc2FaceShapeBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2FaceShape* pEnt = (Gfc2FaceShape*)pEntity;
    target = Gfc2SolidShapeBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasThickness())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(5, pEnt->getThickness(), target);
    }

    if (pEnt->hasPoly())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, pEnt->getPoly(), target);
    }

    if (pEnt->hasMirrorFlag())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(7, pEnt->getMirrorFlag(), target);
    }

    if (pEnt->hasFaceInfo())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(8, pEnt->getFaceInfo(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2FaceShapeBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2FaceShape* pEnt = (Gfc2FaceShape*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2SolidShapeBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2FaceShape_Thickness)
    {
        Gfc2Double value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(input, &value)));
        pEnt->setThickness(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2FaceShape_Poly)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setPoly(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2FaceShape_MirrorFlag)
    {
        Gfc2Boolean value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>(input, &value)));
        pEnt->setMirrorFlag(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2FaceShape_FaceInfo)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setFaceInfo(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}


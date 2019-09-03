#include "StdAfx.h"
#include "Gfc2ImageCurve3dBinarySerializer.h"
#include "FieldCache.h"
#include "Gfc2ImageCurve3d.h"

OBJECTBUF_IMP_OBJECT(Gfc2ImageCurve3dBinarySerializer,"Gfc2ImageCurve3dB",0)

int Gfc2ImageCurve3dBinarySerializer::byteSize(glodon::objectbuf::Entity* pEntity) const
{
    Gfc2ImageCurve3d* pEnt = (Gfc2ImageCurve3d*)pEntity;
    int total_size = Gfc2Curve3dBinarySerializer::byteSize(pEnt);

    if (pEnt->hasCurve())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getCurve());
    }

    if (pEnt->hasSurface())
    {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->getSurface());
    }

    return total_size;
}

void Gfc2ImageCurve3dBinarySerializer::serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2ImageCurve3d* pEnt = (Gfc2ImageCurve3d*)pEntity;
    Gfc2Curve3dBinarySerializer::serializeWithCachedSizes(output, pEnt);

    if (pEnt->hasCurve())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(1, pEnt->getCurve(), output);
    }

    if (pEnt->hasSurface())
    {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(2, pEnt->getSurface(), output);
    }

}

google::protobuf::uint8* Gfc2ImageCurve3dBinarySerializer::serializeWithCachedSizesToArray(google::protobuf::uint8* target, glodon::objectbuf::Entity* pEntity) const
{
    Gfc2ImageCurve3d* pEnt = (Gfc2ImageCurve3d*)pEntity;
    target = Gfc2Curve3dBinarySerializer::serializeWithCachedSizesToArray(target, pEnt);

    if (pEnt->hasCurve())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, pEnt->getCurve(), target);
    }

    if (pEnt->hasSurface())
    {
        target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, pEnt->getSurface(), target);
    }

    return target;
}

glodon::objectbuf::EnParseFieldState Gfc2ImageCurve3dBinarySerializer::parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum, glodon::objectbuf::Entity* pEntity)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
    Gfc2ImageCurve3d* pEnt = (Gfc2ImageCurve3d*)pEntity;
    glodon::objectbuf::EnParseFieldState nState = Gfc2Curve3dBinarySerializer::parseField(input, nFieldNum, pEnt);
    if (nState != glodon::objectbuf::PFS_IGNORE)
    {
        return nState;
    }

    if (nFieldNum == _FieldCache->_Gfc2ImageCurve3d_Curve)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setCurve(value);
        goto success;
    }

    if (nFieldNum == _FieldCache->_Gfc2ImageCurve3d_Surface)
    {
        glodon::objectbuf::EntityRef value;
        DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &value)));
        pEnt->setSurface(value);
        goto success;
    }

    return glodon::objectbuf::PFS_IGNORE;
success:
    return glodon::objectbuf::PFS_SUCCESS;
failure:
    return glodon::objectbuf::PFS_FAIL;
#undef DO_
}

